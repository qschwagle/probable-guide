# Requirements for the UML diagramming app.

## Cross platform

We are targeting users on Mac OS, Linux, and Windows. More esoteric operating systems may be in the far future.
The UI is not meant to be platform integrated. A single UI for all platforms is permited.

### Targets

- Linux ( Debian, Ubuntu, Fedora, Archlinux )
- Mac OS
- Windows 11

## Tablet Support?

Tablets are not currently targeted. However, tablets should be considered for far future target.

### Over all Use Cases

This is a diagramming tool for graphical depictions of various work flows, trees, etc. Primary diagrams for MVP:

- UML diagram
- ERD 
- Use Case diagram
- Activity diagram

##### Basic shapes text boxes

Every shape should be supported as a text box.

- Square, Rectangle, Oval, Circle, Ellipse

##### Labels

A box less text box should be possible for labels

##### Help box support.

The UI should be able to support help boxes.

##### Extendability?

Potentially support saving UI element groups are templates with example text?

Maybe a scripting language for adding on behavior?

#### Storage

We should be able to store the diagram in a cross platform mechanism that can easily be moved by web files.
Online storage is a far future idea.

#### Interface

The UI should be interactive. Users should be able to drag and drop elements. Lines should be automatically be
drawn between elements. Text supported.

#### Internationalization

Internationalization support should be easily available.

#### Support devices / screen readers

Screen readers and support devices should be supported on at least mac os and windows. Linux in the future.

#### Portable

It would be ideal to be able to take snapshots of the diagrams, or even link together smaller diagrams 
for powerpoints and text documents. Therefore, having the ability to create images of entire diagrams or
portions of them would be ideal.

#### Sub diagrams / diagram trees

For complex diagrams, sub diagrams might be useful. Having multiple diagrams connected as sub components could be nice


# Decisions

I am going to use c++ for this implementation. It will be using either opengl or vulkan for the renderer and skia for 2D graphics.
I will either use sdl2 or glfw.

### UI

- glfw or sdl2
- skia
- opengl or vulkan

## Document Storage

- XML (tinyxml2)

## App Storage

- Sqlite
