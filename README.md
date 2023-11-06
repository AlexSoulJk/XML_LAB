# XML_LAB
Laboratory work on storing and implementing an XML document.

## The current version supports the following operations:
1) Downloading from a file. The file must be written in the * format.
2) Saving to a file.
3) Adding a tag.
4) Deleting a tag.
5) Search by name tag or by value.

## Input format:
Sample of tag with name_tag: <name_tag> value = some_value </name_tag>
Sample of tag1, tag2: <name_tag1> value = some_value1
                      <name_tag2> value = some_value2 </name_tag2>
                      </name_tag1>
By the way, samples of input file and output files you can find in this repository.

## Info about iterator++.
Xml_document is stored as a tree whose node contains references to children.
And they also contain references to the father.
When the iterator is shifted, a direct depth-first traversal is used.
