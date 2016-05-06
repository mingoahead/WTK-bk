
### Fl_Widget::user_data

```
void Fl_Widget::user_data	(	void * 	v	)
```
Sets the user data for this widget.

Sets the new user data (void \*) argument that is passed to the callback function.


### Fl_Menu_Item

[detail](http://www.fltk.org/doc-1.3/structFl__Menu__Item.html)

```
struct Fl_Menu_Item {
    const char*    text;     // label()
    ulong          shortcut_;
    Fl_Callback*   callback_;
    void*          user_data_;
    int            flags;
    uchar          labeltype_;
    uchar          labelfont_;
    uchar          labelsize_;
    uchar          labelcolor_;
};
```


### Fl_Widget::color

```
void Fl_Widget::color	(	Fl_Color 	bg	)
```

Sets the background color of the widget.

The color is passed to the box routine. The color is either an index into an internal table of RGB colors or an RGB color value generated using fl_rgb_color().

The default for most widgets is FL_BACKGROUND_COLOR. Use Fl::set_color() to redefine colors in the color map.


### Fl_Widget::selection_color

```
void Fl_Widget::selection_color	(	Fl_Color 	a	)
```

Sets the selection color.

The selection color is defined for Forms compatibility and is usually used to color the widget when it is selected, although some widgets use this color for other purposes. You can set both colors at once with color(Fl_Color bg, Fl_Color sel).


### Fl_Widget::labelfont

```
Fl_Widget::labelfont	(	Fl_Font 	f	)
```

[details](www.fltk.org/doc-1.3/Enumerations_8H.html#a74d2c443f7ab53a6ce5d4ca0c7461bc9)

Sets the font to use.

Fonts are identified by indexes into a table. The default value uses a Helvetica typeface (Arial for Microsoft® Windows®). The function Fl::set_font() can define new typefaces.


### Fl_Widget::labelcolor

```
void Fl_Widget::labelcolor	(	Fl_Color 	c	)
```

Sets the label color.

The default color is FL_FOREGROUND_COLOR.


### Fl_Widget::when

```
void Fl_Widget::when	(	uchar 	i	)
```

[Enumerator](http://www.fltk.org/doc-1.3.x-abi-1.3.3/Enumerations_8H.html#adaaa8b52b78abf3ccce4787b112e6665)
