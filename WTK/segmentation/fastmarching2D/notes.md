
## Pipeline

http://www.itk.org/Wiki/ITK/Tutorials/DOs_and_DONTs

Do call Update() before using the pipeline output
Do call UpdateLargestPossibleRegion() when reusing a reader.

```
        When reusing a reader you must call:
             reader->UpdateLargestPossibleRegion()
        instead of the usual:
             reader->Update()
        Otherwise the extent of the previous image is kept, and in some cases lead to Exceptions
        being thrown if the second image is smaller than the first one.
```
