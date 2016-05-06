# TODO

test data
ITK智能指针

[1]: InsightSoftwareGuide-Book2-4.7.1.pdf
[2]: J.A. Sethian. Level Set Methods and Fast Marching Methods. Cambridge University Press, 1996.

# 4.3 ITK的水平集分割

水平集方法是数值方法用来追踪曲线和曲面的演化。
水平集首先将曲线和曲面作为水平集函数$\Psi(X,t)$的零水平集，然后$\Psi(X,t)$在偏微分方程的约束下演化。在任一时刻，演化曲线可以通过计算零水平集$\Gamma(X,t)={\Psi(X,t)=0}$得到。

水平集的优点在于可以对任意形状建模，可以很好地处理像合并和分离这些拓扑变化。

水平集可以在自治偏微分方程中使用像平均灰度、梯度、边界等信息实现图像分割。一种常见的情况是，先通过手动方式给出一个轮廓，然后这个轮廓不断地演化直到恰好符合目标轮廓，比如一个解剖结构。Sethian 对水平集方法的实现和变种写了一个综述，参见[2][2]。

之后会用实际的例子介绍itk中的几种水平集分割方法。除了FastMarchingImageFilter之外，这些方法的共同点在于每种方法都使用了下面的偏微分方程来计算水平集函数。

\[
\frac{d\Psi}{dt}=-\alpha A(X)\cdot\nabla\Psi-\beta P(X)|\nabla\Psi|+\gamma Z(x)\kappa|\nabla\Psi|
\]

A(X)是水平对流项，P(X)是演进项，Z是对平均曲率$\kappa$的一个修正项。$\alpha,\beta,\gamma$分别表示这三项对边界运动的相对影响。一个分割的filter可以选择性地使用这三项中的任意项。

所有的水平集filter必须使用浮点精度运算以确保结果有效。模板的第三个参数是计算和输出使用的像素类型，默认是float，也可以改为double，也可以使用自定义浮点数据类型。输入图像的像素会自动cast为浮点类型。

大多数filter要求输入两幅图像，一个初始模型($\Psi(X,t=0)$)，一个特征（原始）图像。初始模型必须指定等值边界的值。输出的单幅图像是终止时间对应的$\Psi$。输出图像的零度水平集就是分割结果对应的边界。

ZeroCrossingImageFilter可以在输出结果中找出最佳边界。

[http://fiji.sc/Level_Sets]

影响水平集处理时间的有两个因素，一个是演进边界的大小和演进距离。每次迭代的时间复杂度只和边界大小有关。

一些水平集分割方法对初始条件不敏感，因此适合用区域生长。另一些方法，例如LaplacianSegmentationLevelSetImageFilter很容易卡住，最好是有一个先验的分割作为初始解。并且初始解最好尽可能接近真实结果。当用于高维时，可以使用多尺度降低处理时间。


### 4.3.1 Fast Maching Segmentation

FastMarchingImageFilter.cxx

当自治微分方程形式很简单时，可以使用一个叫做fast marching的算法。

下面的例子介绍FastMarchingImageFilter的使用。

这里自治方程中的速度项使用用户指定的一副图像，通常是原始图像梯度的sigmoid映射。在低梯度区域演进速度相对高梯度区域较快。这样边界能够演进到梯度边界。FastMarchingImageFilter的输出是一副time-crossing图，每个点的像素值代表了演进到改点所需要的时间。给定一个演进时间，可以得到对应时刻的边界。

平滑->梯度->simoid->FastMarchingImageFilter->Threshold
