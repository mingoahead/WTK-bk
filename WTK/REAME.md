source


# logs

### 2015/06/12 Link error

* ����취�����ӿ���� `glu32.lib` `opengl32.lib`
* �ο����ӣ�http://www.itk.org/pipermail/insight-users/2005-April/012874.html
* ��ϸ��

```
1>------ ����������: ��Ŀ: WTK, ����: Release Win32 ------
1>��������ʱ��Ϊ 6/12/2015 2:16:21 PM��
1>InitializeBuildStatus:
1>  ���ڶԡ�D:\Documents\ACA\WTK\WTK\\out\Win32\Release\trash\WTK.unsuccessfulbuild��ִ�� Touch ����
1>ClCompile:
1>  fltkVTKImageViewer.cpp
1>Link:
1>     ���ڴ����� D:\Documents\ACA\WTK\WTK\\out\Win32\Release\WTK.lib �Ͷ��� D:\Documents\ACA\WTK\WTK\\out\Win32\Release\WTK.exp
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glRasterPos2i@8
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: �޷��������ⲿ���� __imp__glRasterPos2i@8
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: �޷��������ⲿ���� __imp__glRasterPos2i@8
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glVertex2f@8
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glClear@4
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glClearColor@16
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glOrtho@48
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: �޷��������ⲿ���� __imp__glOrtho@48
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glPointSize@4
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glPixelStorei@8
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: �޷��������ⲿ���� __imp__glPixelStorei@8
1>fltk_gl.lib(Fl_Gl_Device_Plugin.obj) : error LNK2001: �޷��������ⲿ���� __imp__glPixelStorei@8
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glEnd@0
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: �޷��������ⲿ���� __imp__glEnd@0
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glVertex2d@16
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glDisable@4
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: �޷��������ⲿ���� __imp__glDisable@4
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glBegin@4
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: �޷��������ⲿ���� __imp__glBegin@4
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glShadeModel@4
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glColor4f@16
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glPixelZoom@8
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glBlendFunc@8
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glMatrixMode@4
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glViewport@16
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: �޷��������ⲿ���� __imp__glViewport@16
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glDrawPixels@20
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: �޷��������ⲿ���� __imp__glDrawPixels@20
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glEnable@4
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glColor3f@12
1>FastMarchingLevelSet.obj : error LNK2001: �޷��������ⲿ���� __imp__glLoadIdentity@0
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: �޷��������ⲿ���� __imp__glLoadIdentity@0
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: �޷��������ⲿ���� __imp__glListBase@4
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: �޷��������ⲿ���� __imp__glGenLists@4
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: �޷��������ⲿ���� __imp__wglUseFontBitmapsW@16
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: �޷��������ⲿ���� __imp__glCallLists@12
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: �޷��������ⲿ���� __imp__glRasterPos2f@8
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: �޷��������ⲿ���� __imp__glVertex2i@8
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: �޷��������ⲿ���� __imp__glColor3ub@12
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: �޷��������ⲿ���� __imp__glDeleteLists@8
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: �޷��������ⲿ���� __imp__glReadBuffer@4
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: �޷��������ⲿ���� __imp__glDrawBuffer@4
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: �޷��������ⲿ���� __imp__glGetIntegerv@8
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: �޷��������ⲿ���� __imp__glFlush@0
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: �޷��������ⲿ���� __imp__glCopyPixels@20
1>fltk_gl.lib(Fl_Gl_Choice.obj) : error LNK2001: �޷��������ⲿ���� __imp__wglShareLists@8
1>fltk_gl.lib(Fl_Gl_Choice.obj) : error LNK2001: �޷��������ⲿ���� __imp__wglCreateContext@4
1>fltk_gl.lib(Fl_Gl_Choice.obj) : error LNK2001: �޷��������ⲿ���� __imp__wglCreateLayerContext@8
1>fltk_gl.lib(Fl_Gl_Choice.obj) : error LNK2001: �޷��������ⲿ���� __imp__wglMakeCurrent@8
1>fltk_gl.lib(Fl_Gl_Choice.obj) : error LNK2001: �޷��������ⲿ���� __imp__wglDeleteContext@4
1>fltk_gl.lib(Fl_Gl_Device_Plugin.obj) : error LNK2001: �޷��������ⲿ���� __imp__glPopClientAttrib@0
1>fltk_gl.lib(Fl_Gl_Device_Plugin.obj) : error LNK2001: �޷��������ⲿ���� __imp__glReadPixels@28
1>fltk_gl.lib(Fl_Gl_Device_Plugin.obj) : error LNK2001: �޷��������ⲿ���� __imp__glPushClientAttrib@4
1>D:\Documents\ACA\WTK\WTK\\out\Win32\Release\WTK.exe : fatal error LNK1120: 42 ���޷��������ⲿ����
1>
1>����ʧ�ܡ�
1>
1>����ʱ�� 00:00:07.68
========== ����: �ɹ� 0 ����ʧ�� 1 �������� 0 �������� 0 �� ==========

```


### 2015/06/12 runtime error

* �������main����include֮ǰ���
```
#define vtkRenderingCore_AUTOINIT 4(vtkInteractionStyle,vtkRenderingFreeType,vtkRenderingFreeTypeOpenGL,vtkRenderingOpenGL)
#define vtkRenderingVolume_AUTOINIT 1(vtkRenderingVolumeOpenGL)
```
* �ο����ӣ�http://stackoverflow.com/questions/18642155/no-override-found-for-vtkpolydatamapper
* ��ϸ��
![2015-06-12][/img/20150612143405.png]
