map_gen
=======

Sample code for map generation for a 3D array of cells.

These files are from a larger project which will be built up over time.


defenitions.h:

  Defines arbitrary information that is used repeatedly.


Map_Cell.h:

  Defines the objects: Data, Cell, Grid & Map_Cell.
  
  
  Map_Cell:
  
    Acts as the parent for Grid and Cell allowing Cell to reference either as a parent.
  
  
  Cell:
  
    Contains a Data object, a reference to it's parent, it's id, and an array of 8 Cell's.
    id acts as both a way to identify the game object the Cell reprisents and the depth in the Grid.
    Generates id based on it's position reletive to an absolute observer.
    The id generation is temporary and should change into a terrain generator in later versions.
  
  
  Grid:
  
    Contains a space (3D array) of Cell's.
