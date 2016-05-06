source


# logs

### 2015/06/12 Link error

* 解决办法：链接库添加 `glu32.lib` `opengl32.lib`
* 参考链接：http://www.itk.org/pipermail/insight-users/2005-April/012874.html
* 详细：

```
1>------ 已启动生成: 项目: WTK, 配置: Release Win32 ------
1>生成启动时间为 6/12/2015 2:16:21 PM。
1>InitializeBuildStatus:
1>  正在对“D:\Documents\ACA\WTK\WTK\\out\Win32\Release\trash\WTK.unsuccessfulbuild”执行 Touch 任务。
1>ClCompile:
1>  fltkVTKImageViewer.cpp
1>Link:
1>     正在创建库 D:\Documents\ACA\WTK\WTK\\out\Win32\Release\WTK.lib 和对象 D:\Documents\ACA\WTK\WTK\\out\Win32\Release\WTK.exp
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glRasterPos2i@8
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: 无法解析的外部符号 __imp__glRasterPos2i@8
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: 无法解析的外部符号 __imp__glRasterPos2i@8
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glVertex2f@8
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glClear@4
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glClearColor@16
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glOrtho@48
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: 无法解析的外部符号 __imp__glOrtho@48
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glPointSize@4
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glPixelStorei@8
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: 无法解析的外部符号 __imp__glPixelStorei@8
1>fltk_gl.lib(Fl_Gl_Device_Plugin.obj) : error LNK2001: 无法解析的外部符号 __imp__glPixelStorei@8
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glEnd@0
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: 无法解析的外部符号 __imp__glEnd@0
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glVertex2d@16
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glDisable@4
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: 无法解析的外部符号 __imp__glDisable@4
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glBegin@4
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: 无法解析的外部符号 __imp__glBegin@4
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glShadeModel@4
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glColor4f@16
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glPixelZoom@8
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glBlendFunc@8
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glMatrixMode@4
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glViewport@16
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: 无法解析的外部符号 __imp__glViewport@16
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glDrawPixels@20
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: 无法解析的外部符号 __imp__glDrawPixels@20
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glEnable@4
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glColor3f@12
1>FastMarchingLevelSet.obj : error LNK2001: 无法解析的外部符号 __imp__glLoadIdentity@0
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: 无法解析的外部符号 __imp__glLoadIdentity@0
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: 无法解析的外部符号 __imp__glListBase@4
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: 无法解析的外部符号 __imp__glGenLists@4
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: 无法解析的外部符号 __imp__wglUseFontBitmapsW@16
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: 无法解析的外部符号 __imp__glCallLists@12
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: 无法解析的外部符号 __imp__glRasterPos2f@8
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: 无法解析的外部符号 __imp__glVertex2i@8
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: 无法解析的外部符号 __imp__glColor3ub@12
1>fltk_gl.lib(gl_draw.obj) : error LNK2001: 无法解析的外部符号 __imp__glDeleteLists@8
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: 无法解析的外部符号 __imp__glReadBuffer@4
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: 无法解析的外部符号 __imp__glDrawBuffer@4
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: 无法解析的外部符号 __imp__glGetIntegerv@8
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: 无法解析的外部符号 __imp__glFlush@0
1>fltk_gl.lib(Fl_Gl_Window.obj) : error LNK2001: 无法解析的外部符号 __imp__glCopyPixels@20
1>fltk_gl.lib(Fl_Gl_Choice.obj) : error LNK2001: 无法解析的外部符号 __imp__wglShareLists@8
1>fltk_gl.lib(Fl_Gl_Choice.obj) : error LNK2001: 无法解析的外部符号 __imp__wglCreateContext@4
1>fltk_gl.lib(Fl_Gl_Choice.obj) : error LNK2001: 无法解析的外部符号 __imp__wglCreateLayerContext@8
1>fltk_gl.lib(Fl_Gl_Choice.obj) : error LNK2001: 无法解析的外部符号 __imp__wglMakeCurrent@8
1>fltk_gl.lib(Fl_Gl_Choice.obj) : error LNK2001: 无法解析的外部符号 __imp__wglDeleteContext@4
1>fltk_gl.lib(Fl_Gl_Device_Plugin.obj) : error LNK2001: 无法解析的外部符号 __imp__glPopClientAttrib@0
1>fltk_gl.lib(Fl_Gl_Device_Plugin.obj) : error LNK2001: 无法解析的外部符号 __imp__glReadPixels@28
1>fltk_gl.lib(Fl_Gl_Device_Plugin.obj) : error LNK2001: 无法解析的外部符号 __imp__glPushClientAttrib@4
1>D:\Documents\ACA\WTK\WTK\\out\Win32\Release\WTK.exe : fatal error LNK1120: 42 个无法解析的外部命令
1>
1>生成失败。
1>
1>已用时间 00:00:07.68
========== 生成: 成功 0 个，失败 1 个，最新 0 个，跳过 0 个 ==========

```


### 2015/06/12 runtime error

* 解决：在main函数include之前添加
```
#define vtkRenderingCore_AUTOINIT 4(vtkInteractionStyle,vtkRenderingFreeType,vtkRenderingFreeTypeOpenGL,vtkRenderingOpenGL)
#define vtkRenderingVolume_AUTOINIT 1(vtkRenderingVolumeOpenGL)
```
* 参考链接：http://stackoverflow.com/questions/18642155/no-override-found-for-vtkpolydatamapper
* 详细：
![2015-06-12][/img/20150612143405.png]
