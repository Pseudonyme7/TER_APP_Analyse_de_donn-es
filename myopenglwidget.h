#ifndef MYOPENGLWIDGET_H
#define MYOPENGLWIDGET_H

#include <QObject>
#include <QWidget>
#include <QKeyEvent>
#include <QTimer>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QDebug>
#include <QSurfaceFormat>
#include <QMatrix4x4>
#include <iostream>
#include <QtGlobal>

#ifdef Q_OS_WIN
#include <gl/GL.h>
#include <gl/GLU.h>
#endif


class myOpenGLWidget : public QOpenGLWidget,
			   protected QOpenGLFunctions
{
	Q_OBJECT

public:
	explicit myOpenGLWidget(QWidget *parent = nullptr);
    ~myOpenGLWidget() override;


public slots:

signals:  // On ne les implémente pas, elles seront générées par MOC ;
		  // les paramètres seront passés aux slots connectés.

protected slots:

protected:
	void initializeGL() override;
	void doProjection();
	void resizeGL(int w, int h) override;
	void paintGL() override;

private:
	double m_angle = 0;
	QTimer *m_timer = nullptr;
	double m_ratio = 1;

    QVector<GLfloat> data;

	//RR matrices utiles
	QMatrix4x4 m_modelView;
	QMatrix4x4 m_projection;
	QMatrix4x4 m_model;

	QOpenGLShaderProgram *m_program;
	QOpenGLBuffer m_vbo;

	void makeGLObjects();
	void tearGLObjects();
};


#endif // MYOPENGLWIDGET_H
