# Window

The window is the class of objects that manage the OS windows used to recieve
input from the user and the system and display graphics to the user.

Windows react to events being processed through the operating system or being
sent from callbacks which are handling events from the operating system (glfw).

Windows have a height and a width that maps to the underlying window object. 
They need to update any graphics contexts that rely on that information.
