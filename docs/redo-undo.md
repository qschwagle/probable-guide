# Redo and Undo implementation

Every discrete event is represented by a command object. Discrete events
are done by the user and directly applied to the document. The event is
wrapped and reversible and placed on the modification stack. The modification
stack then can be used to travel forward and back in the time of the document.

### Command Object

An object that handles some form of modification on the underlying body.
Every object must be appliable and revertible.

If its not revertible, then the entire stack must be applied to the document
except the undo-ed operation.


## Modification Stack

The modification stack contains the command objects to transition the document
from a starting state to the current state.

## When is a Command Object created?

Objects are created when a discrete event has completed. So a drag AND drop is a 
complete event. A color change is a complete event. 


