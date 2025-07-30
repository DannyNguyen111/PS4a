# PS4a
AniPlayer


In PS4a, I developed a Static Animation Player in C++ using SFML that parses animation data from JSON files and renders the first frame of a composite animation. The program reads keyframe data including shapes like circles and rectangles, their positions, colors, and transformations. I implemented a component-based system where each shape type is represented by a specific subclass responsible for drawing itself with the correct SFML properties. The AniPlayer class manages parsing the JSON, constructing the scene graph from keyframes and components, and rendering the initial frame without any animation tweening or time-based updates. This setup lays the groundwork for future animation interpolation and interactive playback while demonstrating robust JSON parsing, object-oriented design, and SFML rendering techniques.

AniPlayer Class:
Responsible for loading and parsing the JSON animation file using a JSON library (e.g., nlohmann/json).
Parses top-level data such as animation name, duration, and the list of keyframes.
Constructs a scene graph by creating KeyFrame objects for each keyframe in the JSON.
Holds the current frame index (initially 0) and exposes a draw() method to render the current frame on the SFML window.

KeyFrame Class:
Represents a single frame in the animation timeline.
Stores a collection of Component objects representing shapes or composite groups at that frame.
Parses shape properties such as type (circle, rectangle), position, size, rotation, fill color, and outline color from JSON data.
Supports hierarchical nesting by allowing components to contain child components for complex composite shapes.

Component Base Class and Subclasses:
Abstract base class defines a common interface for drawing and transforming graphical elements.
Subclasses like CircleComponent and RectangleComponent implement specific SFML shapes with properties set from JSON data.
Each component applies its own transformations (position, rotation, scaling) and renders itself when the parent KeyFrame calls draw().
This modular design allows easy extension for new shape types and complex animation structures.

JSON Processing:
The program reads the animation JSON file, validates expected keys, and extracts nested data to build the scene graph.
Colors are parsed from hex strings and converted to SFML sf::Color.
Transform values are parsed and applied precisely to match the animation specification.

Rendering Flow:
On each window draw call, AniPlayer draws the current keyframe’s components onto the SFML render target.
Since PS4a is a static player, it only renders the first keyframe without tweening or animation timing.

<img width="1214" height="864" alt="screenshot" src="https://github.com/user-attachments/assets/14eda47a-c6c8-4eab-b8ba-7844079eb797" />
