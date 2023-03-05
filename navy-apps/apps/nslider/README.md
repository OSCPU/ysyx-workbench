# NSlider

1. copy slides.pdf to `slides/`
2. run `convert.sh`
3. modify the variable `N` in `src/main.cpp` to the total number of the slides

## Error report

If you see the following error, refer to [here][sf] for solution.
```
convert-im6.q16: attempt to perform an operation not allowed by the security policy `PDF' @ error/constitute.c/IsCoderAuthorized/408.
```

[sf]: https://stackoverflow.com/questions/52998331/imagemagick-security-policy-pdf-blocking-conversion
