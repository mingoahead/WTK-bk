

# TODO

* 2015/11/13 [Save改为16位unsigned short标准]
* 2015/11/13 保存stl
* 2015/11/13 保存对比数据（重写？）
* 2015/06/11 搞清楚水平集的公式和实现的对应关系，代码中参数的实际意义
* 2015/06/11 思考如何设计Console类和fltk GUI类
* 2015/06/11 动态交互运行，参数修改能实时显示结果
* 2015/06/11 显示组件设计
* 2015/06/11 fltk类的封装和几个头文件
* 2015/06/29 覆盖层颜色更改

```
	# include "fltkImageViewer.h"
	# include "fltkVTKImageViewer.h"
	# include "fltkProgressBar.h"
	# include "fltkLightButton.h"
```

* 2015/06/23 FastMarching VTK显示
* 2015/06/24 Wtk关闭后，App依然在运行
* 2015/06/24 定制FltkImageViewer
*

# BUG

* 2015/06/25 FltkImageViewer 100张切片显示的序号为0-100，应为0-99
* 2015/06/25 FltkImageViewer 显示区域在刚打开和窗口尺寸变化时不刷新
* 2015/06/25 FltkImageViewer 窗宽窗位调节，数值显示有问题
* ~~2015/06/29 'vtkInteractorStyleJoystickCamera (03BC0848): Timer start failed'~~
  - [solution](http://vtkusers.public.kitware.narkive.com/VqcizA2w/tcl-linux-problem) 按 't'改为trackball模式（BUG触发：按'j'改为joystick模式）
* 2015/06/29 流水线上不能同时执行两个管线，会崩溃

# THINK

* 2015/06/25 如何实现多种语言界面，既有中文也有英文
* 2015/06/25 如何实现全局字体定义，即一次设置所有控件的字体


# LOG

* 2015/06/29 VTK-6.2.0改为VTK-5.10.1


# 2015/11/12
ITK MemoryAllocationError
