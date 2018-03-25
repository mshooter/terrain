TEMPLATE = subdirs
SUBDIRS = demo terrainLib #tests

demo.depend = terrainLib 
tests.depend = terrainLib
