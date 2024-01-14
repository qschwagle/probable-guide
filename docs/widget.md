# Widget

A widget is simply an element on the screen. The UI is a composition of widgets in various
containers.

-  Widget has one or more widgets below it

## Is a widget a class or a interface?

A class would allow for shared behavior. behavior that all widgets share would be reused easily
by simply having a parent Widget which is then specialized into the various elements.

A better way might be simply having a widget be an interface. Only portions of the behavior of
a widget is reused in each widget. Therefore, it would be better to simply use an interface and
keep the type hiearchy flat.

For shared behavior, using composition would be better. Basically the "widget" implementation pushes
the behavior to easily reusable behavior to underlying object via delegation. There can also be
a chain of responsibility as the underlying object can delegate further as an inverted chain where
the underlying object would try to handle it. If it can't it would let the parent handle it.

### Focusable

interface Focusable {
    Widget* hit(pt)
}

### Clickable

interface Clickable {
    bool hit(pt)
}

### Double Clickable

interface DoubleClickable {
    bool hit(point)
}

### Renderable

interface Renderable {
    void Render()
}

### Sizable

interface Measurable {
    Rect Size()
}

### Position

interface Position {
    Point GetPosition() // TopLeft
}

### Disable

interface Disable {
    bool isDisabled()
    void setDisabled(bool)
}

### Draggable 

interface Draggable {
    Widget* draggable()
    List<targettype> targets
}

### Dropzone

interface Dropzone {
    Widget* DropzoneHit(Point pt)
    bool Accept(Draggable* d);
    type dropzone()
}

## Should widgets be encodable / decodable?

We can easily build and store out the trees of a UI using widgets.

## Border and Padding

A border is simply a rectangle behind another rectangle

# Very Basic Data

## Rectangle

- width (double)
- height (double)
- top left Point (double)

## Circle

- top left Point 
- radius

This one is weird. The circle is drawn from r/2, r/2 .

## Point

- x : double
- y : double 

## Line

- start (Point)
- end (Point)
