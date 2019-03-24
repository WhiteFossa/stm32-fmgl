# stm32-fmgl - Fossa's MCU Graphics Library
Display-independedent MCU graphis library

## Features
- Opensource (GPLv3)
- Hardware-agnostic (designed to work with my own L2HAL: https://github.com/WhiteFossa/stm32-l2hal, but can work with any driver, providing functions to set pixels colors)
- Can draw primitives, render texts in English and Russian (KOI8-R encoding) and XBM images
- Render operations done against local framebuffer, which then pushed to display
- Full (all KOI8-R printable characters) font (Terminus 12x6) provided
- Each function is documented
- Well-written (I hope), enterprise-style code
- Demo included

## Demo
See demo here: https://www.youtube.com/watch?v=nj8D-aAEQKA

