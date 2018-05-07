# SwitchRaytracer
A simple raytracer weekend project meant to go on the Switch via fusee gelee at the end. Ported features from my school project 8 years ago (With some new cool syntaxes that I now know)

Contains:
- Spheres!
- Blinn-Phong, Shading and Reflection
- Templated materials (`ReflectingMaterial<BlinnPhongMaterial>(<INSERT ARGUMENTS HERE>);`)

## Post Mortem

I did not realise there was a binary size restriction of 122KB, which I did not meet. But I learned quite a bit about makefiles, even though I hacked this one together. It works on Windows, and it builds for the Switch (Insert sad horn sound here). I need to do more one-weekend projects. 

![Sample screenshot](https://github.com/Querijn/SwitchRaytracer/raw/master/sample.png "Sample")
