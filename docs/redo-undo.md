# Redo and Undo implementation

Each change on the document must be done through command Objects. 


### Command Object

An object that handles some form of modification on the underlying body.
Every object must be appliable and revertible.

If its not revertible, then the entire stack must be applied to the document
except the undo-ed operation.


## Modification Stack

The modification stack contains the command objects to transition the document
from a starting state to the current state.
