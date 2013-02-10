This is [@moritz9422](https://github.com/moritz9422) and mine solution to a small challenge in school. The task was to add 0.0001 to 10000.0 (both `float`) repeated 10M times without arithmetic error. As demonstrated by `trivial.c`, an ordinary loop will fail because of the absorption effect.

We wrote the fastest program, using a minimum heap and running in just under 3 seconds on my laptop, whereas it can take weeks if you get it wrong.
