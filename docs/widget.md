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
    bool hit(pt)
}

### Renderable

interface Renderable {
    void Render()
}

### Sizable

interface Measurable {
    Rect Size()
}

## Should widgets be encodable / decodable?

We can easily build and store out the trees of a UI using widgets.

## Rectangle

- width
- height
- top left position

## Border and Padding

A border is simply a rectangle behind another rectangle

