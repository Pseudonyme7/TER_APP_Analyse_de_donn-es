//R. Raffin, M1 Informatique, "Surfaces 3D"
//tiré de CC-BY Edouard.Thiel@univ-amu.fr - 22/01/2019

#include "myopenglwidget.h"

static const QString vertexShaderFile   = ":/ressources/basic.vsh";
static const QString fragmentShaderFile = ":/ressources/basic.fsh";


myOpenGLWidget::myOpenGLWidget(QWidget *parent) :
    QOpenGLWidget(parent)
{
    qDebug() << "init myOpenGLWidget" ;

    QSurfaceFormat sf;
    sf.setDepthBufferSize(24);
    sf.setSamples(16);  // nb de sample par pixels : suréchantillonnage por l'antialiasing, en décalant à chaque fois le sommet
    // cf https://www.khronos.org/opengl/wiki/Multisampling et https://stackoverflow.com/a/14474260
    setFormat(sf);

    setEnabled(true);  // événements clavier et souris
    setFocusPolicy(Qt::StrongFocus); // accepte focus
    setFocus();                      // donne le focus

    m_timer = new QTimer(this);
    m_timer->setInterval(50);  // msec
    //connect (m_timer, SIGNAL(timeout()), this, SLOT(onTimeout()));
}

myOpenGLWidget::~myOpenGLWidget()
{
    qDebug() << "destroy GLArea";

    delete m_timer;

    // Contrairement aux méthodes virtuelles initializeGL, resizeGL et repaintGL,
    // dans le destructeur le contexte GL n'est pas automatiquement rendu courant.
    makeCurrent();
    tearGLObjects();
    doneCurrent();
}

void myOpenGLWidget::initializeGL()
{
    qDebug() << __FUNCTION__ ;
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);

    makeGLObjects();

    //shaders
    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, vertexShaderFile);  // compile
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, fragmentShaderFile);

    if (! m_program->link()) {  // édition de lien des shaders dans le shader program
        qWarning("Failed to compile and link shader program:");
        qWarning() << m_program->log();
    }
}


void myOpenGLWidget::makeGLObjects()
{
    qDebug() << __FUNCTION__ << endl;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QVector<float> vector = {
                      0.1f, 0.1f, 0, 1, 0, 0,
                      0.5f, 0.5f, 0, 0, 1, 0,
                      -0.1f, 0.1f, 0, 0, 0, 1
                      };

    data.append(vector);

    m_vbo.create();
    m_vbo.bind();

    m_vbo.allocate(data.data(), data.count() * sizeof(GLfloat));
}


void myOpenGLWidget::tearGLObjects()
{
    m_vbo.destroy();
}


void myOpenGLWidget::resizeGL(int w, int h)
{
    qDebug() << __FUNCTION__ << w << h;

    //C'est fait par défaut
    glViewport(0, 0, w, h);

    m_ratio = (double) w / h;
    //doProjection();
}

void myOpenGLWidget::paintGL()
{
    qDebug() << __FUNCTION__ ;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_program->bind(); // active le shader program


    /// Ajout RR pour gérer les 3 matrices utiles
    /// à mettre dans doProjection() pour clarifier
    /// -----------------------------------------
    m_modelView.setToIdentity();
    m_modelView.lookAt(QVector3D(0.0f, 0.0f, 3.0f),    // Camera Position
                       QVector3D(0.0f, 0.0f, 0.0f),    // Point camera looks towards
                       QVector3D(0.0f, 1.0f, 0.0f));   // Up vector

    m_projection.setToIdentity ();
    m_projection.perspective(70.0, width() / height(), 0.1, 100.0); //ou m_ratio

    //m_model.translate(0, 0, -3.0);

    // Rotation de la scène pour l'animation
    m_model.rotate(m_angle, 0, 1, 0);

    QMatrix4x4 m = m_projection * m_modelView * m_model;
    ///----------------------------

    m_program->setUniformValue("matrix", m);

    m_program->setAttributeBuffer("posAttr", GL_FLOAT, 0, 3, 6 * sizeof(GLfloat));
    m_program->setAttributeBuffer("colAttr", GL_FLOAT, 3 * sizeof(GLfloat), 3, 6 * sizeof(GLfloat));
    m_program->enableAttributeArray("posAttr");
    m_program->enableAttributeArray("colAttr");

    qDebug() << "Drawing..." << endl;
    glEnable(GL_PROGRAM_POINT_SIZE);
    glDrawArrays(GL_POINTS, 0, 3);

    m_program->disableAttributeArray("posAttr");
    m_program->disableAttributeArray("colAttr");

    data.clear();
    m_program->release();
}

