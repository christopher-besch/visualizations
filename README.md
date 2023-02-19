# Visualizations

Check out the Floyd-Warshall Algorithm in your desktop web browser: [visualizations.chris-besch.com/warshall](https://visualizations.chris-besch.com/warshall/index.html)

![](https://raw.githubusercontent.com/christopher-besch/visualizations/main/images/05.png)

Everything is written using C++ with [GDNative](https://docs.godotengine.org/en/stable/tutorials/scripting/gdnative/what_is_gdnative.html) in [Godot](https://godotengine.org).
I could have saved a lot of time by using GDScript but I really like C++ and am used to the C++ standard library for competitive programming.
So this repo might be a good reference if you want to see how things can be done in Godot with C++.

To arrange the graph's nodes I use Godot's physics engine and [ForceAtlas2, a Continuous Graph Layout Algorithm for Handy Network Visualization Designed for the Gephi Software](https://journals.plos.org/plosone/article?id=10.1371/journal.pone.0098679).
With a little bit of work, this visualization code can be included in your own project.
If you need some help with that, create an issue and let me know.

![](https://raw.githubusercontent.com/christopher-besch/visualizations/main/images/04.png)

### Commands
- `scons platform=linux -Q compiledb`
- `source ~/.emsdk/emsdk_env.sh && scons platform=javascript -j12 target=release && scons platform=linux -j12 target=release`
- `scons platform=javascript generate_bindings=yes -j12 target=release`

### other
- [https://visualizations.chris-besch.com/globe_torch/globe_torch.html](https://visualizations.chris-besch.com/globe_torch/globe_torch.html)
- [https://visualizations.chris-besch.com/ant_wrumwrum/index.html](https://visualizations.chris-besch.com/ant_wrumwrum/index.html)
- [https://visualizations.chris-besch.com/ant_wrumwrum2/index.html](https://visualizations.chris-besch.com/ant_wrumwrum2/index.html)
