% The Sailcut CAD Handbook

---
author:
- "Robert Lainé"
- "Jeremy Lainé"
lang: en
toc: true
---

# Introduction

## About Sailcut CAD

Sailcut is a software for designing boat sails and developing then into
flat panels. Sails can be either 4 sided sails like for old timer gaff
rig or 3 sided sails like jibs or main sails for Marconi rig.

The first version of Sailcut was developed in 1978 and used by Robert
Lainé for making the sails of his IOR 1/4 ton named "Flying Sheep
III". Sailcut has been available on the web since 1994 and is used by
many professional and amateur sail makers for offshore racing, cruising
and recently for model yacht.

Sailcut uses a unique mathematical definition of the surface of the sail
which ensure that the sail profile is smooth and aerodynamic.

## How to obtain Sailcut CAD?

You can download the latest version of Sailcut CAD from the project's
home page at <https://www.sailcut.org/>.

## Technical information on the code

Sailcut CAD is written with portability in mind. As such it is written
in C++ and uses the Qt library from Trolltech for the graphical user
interface. Sailcut CAD uses OpenGL to display the 3D view of the sail.
Sailcut CAD is known to compile and run on GNU/Linux, Microsoft Windows
and MacOS/X.

# Using Sailcut CAD

## Upgrade notes

As of release 0.6.5, Sailcut CAD uses different extensions for each file
type instead of ending all files with ".xml". If you wish to open
sails created with a previous version of Sailcut CAD you should rename
your sail definition file so that it ends with ".saildef". When
opening the resulting old file, all dimensions data except for the mould
will be preserved. Redefine your sail mould, then save the file.

## User preferences

### Preferences file

Your preferences are stored in a file called `.sailcutrc`. On UNIX-like
platforms, this file is located in your `HOME` directory. On Windows
this file is located in your `Documents and Settings\USER` directory.

### Internationalisation

As of release 0.5.5, Sailcut CAD has support for internationalisation.
Translations of the user interface in various languages are currently
provided. On startup, Sailcut selects the language corresponding to your
locale. You can use the **Language** submenu of the **View** menu to switch to
another language.

# Creating a sail

When you start Sailcut CAD, you are presented with a default sail. At
the top of the window you will find a number of roll down menus. The
**File** menu is used for loading an existing sail, saving the parameters of
the sail and Export the developed panels.

You can modify the dimensions of the sail by using the **Dimensions** entry
of the View menu.

You can modify the profile of the sail through the **Mould** entry of the
**View** menu.

You can display several sails on the same rig through the **Rig** entry of
the **View** menu.

## Dimensions dialog screen

You can access the sail dimensions dialog from the **Dimensions** entry of
the View menu.

The program is tailored to design either triangular or quadrangular boat
sails. A classical triangular sail is essentially a quadrangular sail
with a very small top edge.

The surface of the sail is generated from a single set of equations
defining the profile of the sail at all levels. The profiles rest on the
edges of the sails which are defined by their length and the amount of
round (also called roach) in each side and the twist of the sail. The
**Definition** window is divided into a number of boxes which group the
parameters defining the sail.

You can use the **Compute** button to compute and display ancillary data
like IRC width. This can result in some text box color being changed.
Red color indicate that the value exceed the upper limit and yellow
indicate that it is below the lower limit. The value itself will be
changed to the acceptable limit.

When you have finished entering the dimensions, press **OK** to display the
sail in 3D.

### Rig geometry

The first step is to select the type of sail you are going to work on,
then enter the data defining the correspônding rig geometry and sail
plan such that the sail will have the proper orientation.

Select the type of sail by pressing the corresponding Radio Button:

- **Jib** for any sail which will be set on a stay,

- **Mainsail** for any sail set on a mast,

- **Wing** for any type of kite symetrical about the foot.

The rig data are used for displaying the sails in their proper relative
position with the rig.

![Sailcut plan definition](sailplan.svg){#fig.sailplan}

### Sail identifier

You enter there a text describing the sail you are working on (maximum
40 characters spaces included).

### Sail dimensions

This is where the dimensions of the sail are entered.

On a main sail the minimum value for the gaff length (headboard) is
constrained to 5 mm. Value smaller than that will default back to 5 mm.
The gaff angle is constrained to 90 degrees maximum between the gaff and
the luff.

Positive round (roach) of the luff, foot, leech and gaff extend the sail
outside of the straight edge line.

Negative round is equivalent to hollowing that edge of the sail.

The position of the round or roach is expressed in percentage of the
side length starting from the lower or most leftward end of that edge.

![Sailcut edges definition](sail_edges.svg){#fig.sail_edges}

Dimensions and angles defining the sail plan are expressed in millimetre
and degrees.

Length of the sail sides and diagonal are the 3D straight line distance
between the corners of the sail.

The actual length on the finished sail lais on the floor can be slightly
longer depending on the shape of the sail. For example, the foot length
entered in the screen below is 3600 mm. If the foot camber is null then
that will be the actual distance between clew and tack (straight foot)
of the finished sail. If a 10% camber is entered for the foot depth,
then the actual foot will be the length of the arc which has 10% camber,
that is 2.7% longer than the straight line foot length.

Having entered the sail main dimensions you can press on the **Compute**
button to obtain additional informations on the sail, like the X-Y
coordinates of the corners of the sail, the perpendicular length LP
measured from the clew to the luff as well as IRC racing rules width.

The X-Y coordinates of the sail corners are usefull to quickly adjust
the data entered. For example if you find that the clew height (Y) is
way below or above the height of the tack when you would like it to be
leveled, then you can substract or add the difference to the leech
length.

### Layout

Click on the radio button corresponding to the desired layout of the
sail. The layout of the panels does not affect the shape of the sail
which is defined by its dimensions and its mould.

Except for the Radial cut layout, the number of panels is determined by
the cloth width and seam width entered in the **Cloth** box.

- The most commonly used layout is the **Crosscut**. The panels are laid
  perpendicular to the straight line joining the peak to the clew of
  the sail.

- The **Twist foot** layout is similar to the cross cut except that the
  lower panels are rotated such that they do not intersect the foot of
  the sail.

- The **Horizontal cut** layout lay the seams in the horizontal plane.
  This option can be used to visualise the profile of the sail at
  various levels and to output files with the 3D coordinates of the
  sails for use by CFD tools.

- The **Vertical cut** layout places the panels parallel to the straight
  line joining the peak to the clew of the sail. This is the favorite
  layout for the old timer's main sail.

- The **Mitre cut** layout is the favorite for the old timer's genoa. The
  sail is divided in two parts by a line joining the clew to the mid
  point on the luff and the panels organised to be perpendicular to
  the foot in the lower part of the sail and perpendicular to the
  leech in its upper part.

- The **Radial cut** is used mostly for competition as the cloth is mostly
  aligned with the directions of maximum strain. When using the Radial
  cut option it is important to understand the definition of the
  number of sections, number of radial gores and number of luff gores
  (see [Radial cut gores definition ](#fig.head_gores_definition)).

![Radial cut gores definition](head_gores_definition.svg){#fig.head_gores_definition}

### Sail shape

You enter there the depth of the sail at 3 levels, near the foot, in the
middle of the sail(the exact position being defined in the mould screen)
and near the top of the sail.

The twist angle is the angle expressed in degrees by which the top of
the sail is rotated with respect to the foot. The twist is globally
determined by the amount by which the apparent wind at the top of the
mast is rotated with respect to the apparent wind at deck level. For a
jib the twist is sometime driven by the need to have the upper part of
the leech sufficiently open to clear the spreaders. For a mainsail the
twist is also driven by the ability of the rig to carry the tension in
the leech, in particular a gaff rig will have more twist in its main
sail than a Bermuda rig. It is important that the twist angle entered in
Sailcut reflects the reality of the shape of the leech when sailing in
an average wind.

The sheeting angle value is the actual sheeting angle measured from the
boat centerline when the sail is set on the boat. For a jib the minimum
value is 5 degrees. The value is of importance to ensure that the sail
is properly positioned when displayed in the rig viewer. You can then
visualise for example the slot between a jib and the main sail as set on
the boat.

### Cloth

Enter there the width of cloth used, the width of the seams between
adjacent panels, the width of material to be added to the leech to make
the leech hem and the width of material for the foot hem and for other
edges hems.

[Sailcut seams and hems definition ](#fig.sail_seams) describes the
location of the various hems and seam width. Sailcut will compute the
panels such that they fit within the declared cloth width including the
seam and hems width as appropriate, except for a radial cut sail for
which the width of each panels is computed from the number of radial
panels entered.

Note that when using the radial layout, the seam width between
horizontal sections will be twice the width of the seams between
adjacent panels of the same section.

![Sailcut seams and hems definition](sail_seams.svg){#fig.sail_seams}

## Mould dialog screen

You can access the mould dialog from the **Mould** entry of the **View** menu.

The depth and the shape of the sail can be entered at three levels
located at the bottom (foot) the middle (sail's maximum depth height
can be adjusted) and at the top of the sail.

The position of the point of maximum depth of a profile is shown under
the depth value. This position which depend of the luff and leech shape
factors is expressed in relation to the cord of the profile. For
exemple: 0.34 means that the point of maximum depth is at 34% of the
local cord counting from the luff end of the profile.

The luff shape and the leech shape can be adjusted for the Top profile
and Middle profile only. The foot profile is always an arc of circle.

Under the luff shape factor, the corresponding value of the angle of
entry of the profile is provided in degree. The angle under the leech
shape factor is the exit angle of the profile. These angles are refered
to the local cord and if you want to know for exemple the real entry
angle of a profile with respect to the axis of the boat you have to add
to the entry angle the twist at the level of the profile plus the
sheeting angle.

The vertical position of the sail's maximum depth profile is controled
by the vertical slide bar to the right of the left vertical frame.

In order to avoid that the leech makes a hook in the upper part of the
sail when the wind increases, it is recommended that the Top profile
luff shape value be higher than that of the middle profile and that the
leech shape value at the top be lower than the middle value.

## View controls

It is possible to zoom, pan and rotate the sail in the view window:

- **Rotation** : you can control the rotation that is applied to the sail
  by using the elevation and azimuth sliders located at the edges of
  the graphic pane.

- **Pan** : click on a point with the left mouse to center the view on
  that point.

- **Zoom** : to zoom in press CTRL + and to zoom out press CTRL -. You can
  also use the **zoom** buttons in the view controls or your mouse wheel
  to zoom in and out.

## Sail panels development

The developed sail is display by clicking on the **Development** tab from
Sailcut CAD's main window. This presents you with a view of the
developed (flat) panels of the sail. The view controls are the same as
those of the main window. The blue line represents the edge of the
finished panel (draw line) and the red line represents the outer edge
taking into account the seam and hems width allowance (cut line).

You can export the points which define the edges of the developed panels
with the draw line and the cut line to the following file formats from
the Export development submenu of the **File** menu:

- Carlson Design plotter (.sp4) using the **to Carlson plotter** menu
  entry.

- DXF file using the **to DXF** menu entry. All the panels will be placed
  in a single file with one panel per layer.

- Multiple DXF files using the **to DXF (split)** menu entry. Each panel
  will be placed in a separate file on layer 1. The name of the file
  is the base name entered completed with the number of the panel
  (0,1,2,...).

- XML dump of the points using **to XML sail** menu entry (see
  [XML representation of a sail](#s.format_xml_sail) for file format
  details).

- plain ASCII text dump of the points using the **to TXT sail** menu entry
  (see [Text representation of developed sail](#s.format_text_flat)
  for file format details).

## Loading and saving sails

Once you have customised your sail, you can save it to a file by using
the **Save** or **Save As** entries in the **File** menu. You can reload
it by using the **Open** entry of the **File** menu next time you want
to work on it.

Both the sail's dimensions and the parameters of the mould are saved
simultanously. This feature allows you to reload a sail and reuse its
mould even if you change the dimensions of the sail to fit a new rig.

Sailcut CAD uses XML files to store the sail data. These files are plain
text so they can easily be viewed using your favourite text editor.

## Exporting 3D sails

In addition to Sailcut CAD's native file format, it is possible to
export all the 3D points located on the edges and seams of the panels
that make up a sail. You can export the three dimensional sail to the
following file formats from the Export 3D sail submenu of the **File** menu:

- DXF file using the **to DXF** menu entry. All the panels will be placed
  in a single file with one panel per layer.

- Multiple DXF files using the **to DXF (split)** menu entry. Each panel
  will be placed in a separate file on layer 1. The name of the file
  is the base name entered completed with the number of the panel.

- XML dump of the points using the **to XML sail** menu entry (see [ XML
  representation of a sail ](#s.format_xml_sail) for file format
  details).

- Plain ASCII text dump of the points using the **to TXT sail** menu entry
  (see [Text representation of 3D sail](#s.format_text_sail) for
  file format details).

- SVG (Scalable Vector Graphics) file using the **to SVG** menu entry.

## Printing data and drawings

The **Print** submenu of the **File** menu offers various printout
possibilities:

- The **data** menu entry will print the data of the sail.

- The **drawing** menu entry will print a drawing of the complete sail. A
  dialog box allows to preview the printout with a spin box to adjust
  the scale factor. The scale factor is the factor by which the sail
  size is multiplied to obtain the drawing size. The scale factor can
  be as small as 0.001 (1000 mm sail will be printed as 1mm), the
  default value is such that the sail fits in 80% of the paper size.

- The **develop** menu entry will print all the developed panels with key
  points coordinates (1 panel per page). A dialog box allows to
  preview the printout with a spin box to adjust the scale factor as
  for the complete sail. The layout of the paper is set to landscape.
  The definition of the developed panel key points coordinates is
  given in [Developed panels drawing](#fig.develop_panel_drawing).
  The X,Y coordinates are absolute coordinates referenced to the lower
  left corner of the box enveloping the contour of the CUT line of the
  panel (edge of cloth). The dX,dY coordinates are relative to the
  straight line joining the end of the corresponding edge and it
  should be remembered that the origin of dX is at the left end of the
  edge and positive value of dY indicate that the point is left of the
  straight line joining the origin to the end points of the edge.

The printout scaling is such that the sail drawing and the largest
developed panel automatically fit in one page. For printing panels to a
precise scale it is preferable to export the developed sail in a DXF
file and use a CAD package to print the panels.

![Developed panels drawing](develop_panel_drawing.svg){#fig.develop_panel_drawing}

# Creating a rig

This module allow the design of a mast with up to 3 levels of spreaders.
It is accessed via the **Rig** entry of the main screen's **File New** menu.

The **Dimensions** entry of the **View** menu will display the screen from
which you can enter and modify the dimensions of the rig.

The definition of the various dimensions is given in
[Sailcut Rig definition](#fig.rigplan). Please note that, in order to
allow the design of sails independently from the design of the rig, the
definition of the mast rake and mast curve are refered to the full mast
length which are different from that of the sail luff rake and curve of
the sail design module which are refered to the sail luff length. This
rig module provides the data to be used when designing the mainsail
which fit on the rig.

![Sailcut Rig definition](rigplan.svg){#fig.rigplan}

## Saving and Loading a rig file

The **Save** entry of the **File** menu is used to save a rig.

Any rig which has been saved can be later opened as an entity with the
**Open** entry of the **File** menu and can be used as an element to
constitute a boat.

## View controls

The controls of the viewer are identical to those of the sail viewer.
You can rotate the rig with the sliders located around the graphic
display, zoom with the mouse's wheel, pan with the mouse left click,
view in wireframe or shaded surface modes.

## Rig dimensions

The Dimensions entry of the View menu display the rig dimension screen
which is divided in boxes corresponding to the entities listed below.

Note that angles are expressed in degrees and linear dimensions in
millimetres.

### Rig ID

A free text identifying or describing the rig can be entered in this
box. The number of characteres is limited to 40.

### Fore triangle

The height *= I* and base *= J* of the fore triangle are entered in the
corresponding fields. Note that the dimensions are measured in the
vertical and horizontal directions. In particular be carefull when
measuring the *J* dimension when the mast is inclined.

### Mast

The mast is assumed to have a constant section from foot to tip. The
heights are refered to the stem fitting horizontal plane.

*Mast height = MH* is the straight line height of the mast top above the
stem. It shall be greater than J.

*Mast round = MRnd* is the maximum deviation from the straight line.

*Mast round position = MRndPos* spin box is used to enter the relative
height of the point at which the mast round is measured. It is expressed
in percentage of the mast height.

*Mast rake = MRkM* is the horizontal distance between the tip of the
mast and its foot. Sailcut CAD will compute and display the
corresponding mast rake angle = MRkD.

*Mast cord = MC* is the fore-aft width of the mast section.

*Mast width = MW* is the transverse width of the mast section.

### Mainsail

See below the chapter about mainsail luff curve.

### Shrouds

*Cap shrouds height = CSH* is the height of the point of attachment of
the outer shroud to the mast.

*Cap shrouds base width = CSB* is the base width of the outer shroud
measured from the central line.

*Lower shrouds base width = LSB* is the base width of the lower (inner)
shroud which shall be smaller or equal to the cap shroud base width.

### Spreaders

*Number of spreaders = SPNB* can be from 0 (none) to maximum 3. If only
no spreader is present, the outer shroud will be identical to the lower
shroud.

*Spreaders height SPH* are entered in ascending order with 1 being the
lowest.

*Spreaders length SPW* are measured from the ecentral line.

### Checking and validating data

Use the **Check** button any time after entering new data to perform a
verification that the data entered are consistant with a reasonable rig
design and the ancillary data are computed. In case of inconsistancy
between data, the color of the fonts will tell you which data is
suspicious. Red indicate a too high value, purple a too low value and
blue signals which related parameter is to be checked.

Once you have entered all necessary data, click on the **OK** button to
close the rig dimensions window and display it. If there is an
incompatibility in the data, the dimensions window will not close until
it is corrected.

## Mainsail luff curve

In most case users have designed sails independently from the design of
a rig. However the user may wish to design a sail compatible with a rig.
In the rig dimensions screen, the box labeled **Mainsail** is used to
compute the mainsail tack position and luff curve which will fit the
rig. These data can be used for creating the corresponding mainsail or
to verify that a mainsail luff curve will fit the rig.

The only data to be entered are the mainsail *tack height = BAD* and
*head height = HAD*. Sailcut CAD will compute the other data.

# Creating a hull

*Please note that this module is not yet fully operational, for the time
being a single chine hull ouline will appear whatever the number of
chine is entered.*

This module allow the design of a hard chines hull. It is accessed via
the Hull entry of the main screen's **File** New menu.

## View controls

The controls of the viewer are identical to those of the sail viewer.
You can rotate the hull with the sliders located around the graphic
display, zoom with the mouse's wheel, pan with the mouse left click,
view in wireframe or shaded surface modes.

## Saving and Loading a hull file

The **Save** entry of the **File** menu is used to save a hull.

Any hull which has been saved can be later opened as an entity with the
Open entry of the **File** menu and can be used as an element to constitute
a boat.

## Hull dimensions

You can modify the dimensions of the hull by using tab **Deck and bottom**
of the screen **Dimensions** entry of the **View** menu.

The *deck and bottom* screen is divided in boxes in which the various
dimensions of the hull are entered.

The hull is constructed upward from the bottom planks. The most
important line is the chine which defines the outer edge of the bottom
planks. The height are refered to any arbitrary horizontal datum plane
located conveniently near the bottom of the hull. Angles are measured in
degrees from the same horizontal datum plane.

### Hull ID

A free text identifying or describing the hull being designed can be
entered in this box.

### Deck

*Forward height*

*Aft height*

### Bottom

*Length*

*Stem angle*

*Transom angle*

*Forward height*

*Chine angle*

*Aft height*

*Max width*

*Max width position*

*Aft width*

*Forward shape*

*Aft shape*

*Dead rise angle*

*Bottom sweep angle*

### Planking

*Number of planks*

*Automatic planking*

*Top plank angle*

*lower plank angle*

### Checking and validating data

Use the **Check** button any time after entering new data to perform a
verification that the data entered are consistant with a reasonable hull
design and the ancillary data are computed. In case of inconsistancy
between data, the color of the fonts will tell you which data is
suspicious. Red indicate a too high value, purple a too low value and
blue signals which related parameter is to be checked.

Once you have entered all necessary data, click on the **OK** button to
close the hull dimensions window and display it. If there is an
incompatibility in the data, the dimensions window will not close until
it is corrected.

## Planks adjustment

Individual side planks can be ajusted by using the tab **Planks** of the
screen **Dimensions** entry of the **View** menu.

The *planks* screen is divided in boxes in which the various dimensions
of the hull are entered.

### Forward height

### Aft height

### Plank angle

### Sweep angle

### Chine angle

### Checking and validating data

Use the **Check** button any time after entering new data to perform a
verification that the data entered are consistant with a reasonable hull
design and the ancillary data are computed. In case of inconsistancy
between data, the color of the fonts will tell you which data is
suspicious. Red indicate a too high value, purple a too low value and
blue signals which related parameter is to be checked.

Once you have entered all necessary data, click on the **OK** button to
close the hull dimensions window and display it. If there is an
incompatibility in the data, the dimensions window will not close until
it is corrected.

# Creating a boat

This boat design module allows you to assemble hull, rig and sails files
created earlier and make a virtual boat. It is accessed via the **Boat**
entry of the main screen's **File New** menu.

## View controls

The controls of the viewer are identical to those of the sail viewer.
You can rotate the hull with the sliders located around the graphic
display, zoom with the mouse's wheel, pan with the mouse left click,
view in wireframe or shaded surface modes.

## Adding and removing boat elements

The boat viewer is initially showing a black screen and files are added
via the **Add** entry of the main screen's **File** menu. A new tab will
appear with the details of the file selected and the element identification
which was given at the time of creating the element (sail ID, Rig ID,
Hull ID).

A boat element can be removed by selecting the corresponding tab and
then clicking on the **Remove** button.

## Saving and loading a boat file

The **Save** entry of the **File** menu is used to save the file of a boat
with any combination of hull rig and sails.

The file of a boat can be opened as an entity with the **Open** entry of the
**File** menu.

## Shifting boat elements

All boat elements will be displayed in the position entered at the time
the element was created. Please remember that the point of coordinate
X=0, Y=0, Z=0 is located at the forward end of the deck of the hull
(stem).

The boat elements can be individually shifted in X, Y or Z direction by
adjusting the corresponding offset in the element spinbox, then clicking
on the **Update** button.

At any time, clicking on the **Reload** button will restore the
corresponding element to its initial position.

# Sails surface formulation in Sailcut

This section is a translation of the paper presented by Robert Lainé to
the second Workshop Science Voile IRENAV in Brest, France, on 21 May
2004.

## History

Sailcut software was initially written in 1978 in Basic language on a
computer with 1.6 KB of memory, one line text screen and a small 32
columns text printer. Hence the necessity to keep the surface
formulation simple for designing the sails which I built and used on my
IOR ¼ton.

This short cycle: "design => manufacturing => utilisation =>
modification", without commercial constraints linked to sailmakers work
habits has allowed me to converge quickly on a compact and robust way of
describing the sail surface. The method is valid for classical
triangular sails and also for quadrangular sails used on old timers and
modern rigs with very large headboard. Later on, the use of Sailcut by
professional sailmakers has necessitated the addition of graphic
interface to the kernel of Sailcut, but that is an other story. Since
1993 the Microsoft Visual Basic version of Sailcut is available at
<https://www.sailcut.org/> and since 2003, the source code of Sailcut
re-written in C++ is available at <https://www.sailcut.org/>.

## Of the complexity of the definition of the surface of a sail

A sail is a complex surface which sailmakers have historically defined
by notions like depth at various height and position of the point of
maximum depth along the local cord of the profile. This method of
defining the surface of the sail by control points allows for an easy
comparison of the shape between the intended design and reality.
Unfortunately a large number of different surfaces can pass through
these few control points. Then notions like the slope at the leading
edge and trailing edge of the profiles were introduced to help sailmaker
get a better control of the shape of the sail profile. Using
interpolation between basic control points, with or without constraints
on the tangents at the extremities of the profiles, to determine the
depth of the sail in all points were too demanding for old days personal
computer processing capability.

From the beginning of my racing activities, I was interested in the
aerodynamic of sails. The books Theory of wings sections by Ira H.
Abbott and Albert E. von Doenhoff, and Sailing Theory and Practice by
C.A. Marchaj convinced me that the distribution of camber along the
profile was the determining factor in the quality of a sail profile. I
was very sceptical about the definition of a profile by its depth, the
position of its maximum depth along the cord and segments of cubic or
quadratic curves on either side. Rather than trying to reproduce
existing sail shape based on depth measurements, I looked for a law of
distribution of its camber giving a reasonably aerodynamic profile on
the complete sail surface. The first attempt was to model directly the
distribution of camber, however that required to process simultaneously
the first and second derivative of the surface many points of the sail
surface, far too much work for my small computer. At the time I was
racing on the North Sea often in relatively heavy weather for my ¼ ton
and I wanted sail profiles with a high peak of pressure very far forward
to fight against the tendency of the depth to move backward as the cloth
stretched in increasing winds. I finally selected a simple equation
defining only the second derivative of the profile and giving a
monotonic decrease of its value along the cord of the profile.
Experience showed that with the then available cloth, the leech was
sometime falling to leeward in the upper part of the sail. I then
introduced a second term in the equation to be able to control the
minimum value of the second derivative at the leech. This equation is
therefore controlled by only two parameters.

## Some Maths

The coordinate system used is such that the plane X-Y contains the tack,
the clew and the head of the luff. The X axis is horizontal and
orientated positively from tack toward clew. The Y axis is vertical
orientated upward and the Z axis (depth) is perpendicular to the X-Y
plane. Profiles are defined by the intersection of the surface of the
sail with an horizontal plane parallel to Z-X plane. The depth Z of any
point of a given profile is a function of the local X ordinate
normalised to the profile local cord as shown in [ Sailcut coordinate
system ](#fig.coordinates_system).

![Sailcut coordinate system](coordinates_system.svg){#fig.coordinates_system}

The following equation is used to describe the second derivative of the
profile function of X:

    Z''= K*[-A*(1-X)^AV - AR*X]

After a first integration it gives the slope of the profile:

    Z'= K*[A*(1 - X)^(AV + 1) / (AV+1) - AR/2*X^2 + C]

Finally after a second integration the equation giving the depth at any
point is:

    Z = K*[-A*(1-X)^(AV+2) / (( AV+2)*(AV+1)) - AR/6*X^3 + C*X + B]

To meet the profile end conditions (X=0, Z=0) and (X=1, Z=0) the
constants B and C are:

    B = A / ((AV + 2) * (AV + 1))
    C = AR / 6 - B

The maximum depth is obtained when the slope Z' is equal to zero, this
allow to calculate K such that the depth at that point is the one
desired.

The factors AV and AR give a measure of the camber at the leading edge
(AV) and trailing edge (AR). Together with the maximum depth value these
factors are sufficient to describe the profile of the sail at any
height.

The factor A defines different families of profiles with a different
distribution of fullness fore/aft. In practice A = 1 give good profiles
for sails used in light conditions. I prefer to use sail profiles with
more fullness forward and a flatter leech as obtained with the factor A
= 1 + AV / 4. This is the factor used in Sailcut and it give a good
range of utilisation of the sails.

The following table give an example of profile data obtained with the
above equations.

    AV = 5.00
    AR = 0.02
    K = 2.94
    A = 2.250
    B = 0.054
    C =-0.050
    curvature = z" / (1+ z'*z')^3/2

| x   | z"     | z'     | z      | curvature |
|-----|--------|--------|--------|-----------|
| 0.0 | -6.615 | 0.955  | 0.00   | -2.503    |
| 0.1 | -3.912 | 0.438  | 0.0674 | -3.007    |
| 0.2 | -2.179 | 0.140  | 0.0949 | -2.117    |
| 0.3 | -1.129 | -0.021 | 0.1000 | -1.129    |
| 0.4 | -0.538 | -0.101 | 0.0934 | -0.530    |
| 0.5 | -0.236 | -0.138 | 0.0812 | -0.230    |
| 0.6 | -0.103 | -0.154 | 0.0665 | -0.099    |
| 0.7 | -0.057 | -0.161 | 0.0507 | -0.055    |
| 0.8 | -0.049 | -0.166 | 0.0343 | -0.047    |
| 0.9 | -0.053 | -0.172 | 0.0174 | -0.051    |
| 1.0 | -0.059 | -0.177 | 0.00   | -0.056    |

Having defined a single equation for all profiles it is a matter of
varying the maximum depth and the factors AV and AR as function of the
height of the profile to generate the complete surface of the sail. The
profile at foot level being always an arc of circle, the factors AV and
AR are equal to zero and only the depth of the foot is entered by the
user. A profile called "mid profile" is located around the middle of
the height and the factors AV and AR are set such that the profile has
the required shape. A third control profile defined as for the "mid
profile" is located at the top of the sail. For all other profiles the
depth value is interpolated by a quadratic equation and the factors AV
and AR are interpolated linearly between between the foot, the middle
and top values.

In total 3 values of depth, 2 pairs of factor (AV, AR) and the vertical
position of the "mid profile" are used to define the basic mould of
the sail.

Note that in Sailcut software the value displayed for the luff factor is
equal to the AV ceofficient while the leech factor displayed is 50 time
the AR coefficient used in the above equations such that the users can
use more friendly range of data than second and third decimal figures.

## Other aspects of the surface formulation

The above basic mould is not sufficient to define a real sail. Indeed
the luff, gaff, leech and foot of the sail are never straight and
further more the sail profiles are always twisted from the foot to the
top of the sail. I use the distance from the point of maximum round to
the straight line and two arcs of parabola rejoining the adjacent
corners to define the real edges of the sail. The profiles defined by
the sail mould described above are resting on the real edges of the
sail. The twist of the sail is finally obtained by applying to each
profile a rotation around the leading edge end point.

It is to be noted that this method of modelling the surface of sails
gives shapes without bumps or hollows and guarantees that there is no
inversion of camber in the profiles. The method is applicable to
triangular and quadrangular sails and Sailcut is commonly used for
designing old timers gaff sails.

# Where can I find more information about Sailcut CAD?

The Sailcut CAD project lives at <https://www.sailcut.org/>. This is
where you will find links to all matters related to Sailcut CAD!

## I think I found a bug, what should I do?

Sailcut CAD is constantly under development and feedback from users is
very welcome! If you think you found bug, visit Sailcut's homepage ,
you will find instructions in the "Reporting a Bug" section.

## I would like to help develop Sailcut CAD, what should I do?

You can help us improve Sailcut even if you are not a programmer! Simply
using Sailcut and reporting any bugs you might find is of considerable
help to us. We are also looking for people to help keep translations up
to date and to produce new translations. If you are interested in
translating Sailcut into your native language, visit the Sailcut CAD
homepage and send an email to the development mailing list!

If you have some knowledge of C++ and are interested in making Sailcut
CAD a better program, visit the Sailcut CAD homepage where you will find
both snapshots of the Sailcut CAD code and how to access to the CVS
repository. Once you have had a chance to familiarise yourself with the
code, contact us via the forums or our mailing lists!

# File formats used by Sailcut CAD

## Text representation of developed sail {#s.format_text_flat}

This section describes the structure of the file generated by Sailcut
CAD using the **to TXT sail** entry of the **Export** development submenu
of the **File** menu. The extension of a text sail file is ".txt".

A sail is made of a number of panels, each panel has 4 basic sides :
left, top, right, bottom which are joined by a drawing line. The origin
is at the bottom left corner of a rectangle surrounding the panel. These
four basic sides define the net area of the panel after assembly in the
sail.

Around the basic panel there is provision for stiching the panels and
sail edge hems, the outer side of the panel is defined by four sides
named *cutLeft*, *cutTop*, *cutRight*, *cutBottom* and the material is
cut along these sides.

Depending on whether or not you have added material for hems around the
sail some of these sides may be identical to the basic sides of the
panel.

    Test main sail cross cut (flat)   // name of the sail
    ===== CPanel : 0 ====           // begining of panel 0
    == CPanelLabel : name ==        // marker for panel label name
    0
    == CPanelLabel : height ==      // marker for label height
    5
    == CPanelLabel : color ==       // marker for label color
    1
    == CPanelLabel : origin ==      // marker for label origin coordinates
    427.717 764.064 0               // X Y Z coordinates (Z is always =0)
    == CPanelLabel : direction ==   // marker for label orientation
    168.204 -57.8975        0
    == CSide : left ==              // begin left side of panel
    #0      92.5718 886.006 0       // X Y Z coordinates of point 0
    #1      92.5718 886.006 0       // X Y Z coordinates of point 1
    ...
    == CSide : top ==               // begin top side
    #0      92.5718 886.006 0       // X Y Z coordinates of point 0
    #1      262.77  886.006 0
    ...
    == CSide : right ==             // begin right side
    #0      3533.09 25.5986 0
    #1      3526.2  169.113 0
    ...
    == CSide : bottom ==            // begin bottom side
    #0      92.5718 886.006 0
    #1      259.921 823.943 0
    ...
    == CSide : cutLeft ==           // begin left cut line
    #0      0       899.006 0       // X Y Z coordinates of point 0
        of left cut line
    #1      0       899.006 0
    ...
    == CSide : cutTop ==            // begin top cut line
    #0      1150.25 899.006 0
    #1      262.77  899.006 0
    ...
    == CSide : cutRight ==          // begin right cut line
    #0      3574.36 0       0
    #1      3566.15 171.031 0
    ...
    == CSide : cutBottom ==         // begin bottom cut line
    #0      0       899.006 0
    #1      252.966 805.191 0
    ...
    ===== CPanel : 1 ====           // beginning of panel 1
    == CPanelLabel : name ==        // marker for panel label name
    1
    == CPanelLabel : height ==
    5
    == CPanelLabel : color ==
    1
    == CPanelLabel : origin ==
    889.341 2.64113 0
    == CPanelLabel : direction ==
    170.396 0.562482        0
    == CSide : left ==
    #0      548.746 0.388633        0
    #1      367.439 68.706  0
    ...
    == CSide : top ==
    #0      203.679 871.331 0
    #1      393.052 872.078 0
    ...

## Text representation of 3D sail {#s.format_text_sail}

This section describes the structure of the file generated by Sailcut
CAD using the menu **to TXT sail** entry of the **Export 3D sail** submenu of
the **File** menu. The extension of a text sail file is ".txt".

A 3D sail is made of a number of panels, each panel has 4 basic sides :
left, top, right, bottom which are joined by a drawing line.

    Test main sail cross cut (3D)   // name of the sail
    ===== CPanel : 0 ====           // begining of panel 0
    == CPanelLabel : name ==        // marker for panel label name
    0
    == CPanelLabel : height ==      // marker for label height
    5
    == CPanelLabel : color ==       // marker for label color
    1
    == CPanelLabel : origin ==      // marker for label origin coordinates
    427.717 764.064 0               // X Y Z coordinates (Z is always =0)
    == CPanelLabel : direction ==   // marker for label orientation
    168.204 -57.8975        0
    == CSide : left ==              // begin left side of panel
    #0      92.5718 886.006 0       // X Y Z coordinates of point 0
    #1      92.5718 886.006 0       // X Y Z coordinates of point 1
    ...
    == CSide : top ==               // begin top side
    #0      92.5718 886.006 0       // X Y Z coordinates of point 0
    #1      262.77  886.006 0
    ...
    == CSide : right ==             // begin right side
    #0      3533.09 25.5986 0
    #1      3526.2  169.113 0
    ...
    == CSide : bottom ==            // begin bottom side
    #0      92.5718 886.006 0
    #1      259.921 823.943 0
    ...
    ===== CPanel : 1 ====           // beginning of panel 1
    == CPanelLabel : name ==        // marker for panel label name
    1
    == CPanelLabel : height ==
    5
    == CPanelLabel : color ==
    1
    == CPanelLabel : origin ==
    889.341 2.64113 0
    == CPanelLabel : direction ==
    170.396 0.562482        0
    == CSide : left ==
    #0      548.746 0.388633        0
    #1      367.439 68.706  0
    ...
    == CSide : top ==
    #0      203.679 871.331 0
    #1      393.052 872.078 0
    ...

## XML representation of a sail {#s.format_xml_sail}

This describe the structure of the file generated by Sailcut using the
menu **to XML sail** entry of the **Export development** or **Export 3D sail**
submenus of the **File** menu. The extension of an XML sail file is
".sail3d".

A sail is made of a number of panels Each panel has 4 basic sides :
left, top, right, bottom which are joined by a drawing line. The origin
is at the bottom left corner of a rectangle surrounding the panel. These
four basic sides define the net area of the panel after assembly in the
sail. Around the basic panel there is provision for stiching the panels
and sail edge hems, the outer side of the panel is defined by four sides
named cutLeft, cutTop, cutRight, cutBottom and the material is cut along
these sides. Depending on whether or not you have added material for
hems around the sail some of these sides may be identical to the basic
sides of the panel.

    <!DOCTYPE Sailcut >
    <CSailDoc>                          // header begin file
    <CSail name="sail" >                // begin sail + name of sail
    <vector size="10" name="panel" >    // indicate that the sail is made
                                           of 10 panels
    <CPanel name="0" >                  // begin panel 0
    <CSide name="left" >                // begin of left side of the panel
    <vector size="7" name="point" >     // number of points on left side is 7
    <CPoint3d name="0" >                // first point = 0
    <real value="92.5718" name="x" />   // first point coordinate X
    <real value="886.006" name="y" />   // first point coordinate Y
    <real value="0" name="z" />         // coordinate Z is always 0
                                        // for a developped panel
    </CPoint3d>                         // end of first point
    <CPoint3d name="1" >                // second point = 1
    <real value="92.5718" name="x" />
    <real value="886.006" name="y" />
    <real value="0" name="z" />
    </CPoint3d>                         // end of second point
     ...
    </vector>                           // end of list of left side points
    </CSide>                            // end of left side
    <CSide name="top" >                 // begin top side
    <vector size="21" name="point" >    // number of points on top side is 21
    <CPoint3d name="0" >                // first point = 0
    <real value="92.5718" name="x" />
    <real value="886.006" name="y" />
    <real value="0" name="z" />
    </CPoint3d>
    <CPoint3d name="1" >                // second point = 1
    <real value="262.77" name="x" />
    <real value="886.006" name="y" />
    <real value="0" name="z" />
    </CPoint3d>
     ...
    </vector>                           // end list of points of top side
    </CSide>                            // end top side
    <CSide name="right" >               // begin right side
     ...
    </CSide>                            // end right side

    <CSide name="bottom" >              // begin bottom side
     ...
    </CSide>                            // end bottom side

    <int value="1" name="hasHems" />    // header indicating that the panel
                                           has hems cloth around the edges
    <CSide name="cutLeft" >             // begin left side cut line
    <vector size="7" name="point" >     // left side has 7 points
    <CPoint3d name="0" >                // first point = 0
    <real value="0" name="x" />
    <real value="899.006" name="y" />
    <real value="0" name="z" />
    </CPoint3d>                         // end first point
     ...
    </vector>                           // end list of left side points
    </CSide>                            // end left side cut line
    <CSide name="cutTop" >              // begin top cut line
     ...
    </CSide>                            // end top cut line
    <CSide name="cutRight" >            // begin right cut line
     ...
    </CSide>                            // end right cut line
    <CSide name="cutBottom" >           // begin bottom cut line
     ...
    </CSide>                            // end bottom cut line
    </CPanel>                           // end of first panel
    <CPanel name="1" >                  // begin second panel = 1
    <CSide name="left" >                // begin left side
    <vector size="7" name="point" >
    <CPoint3d name="0" >
    <real value="548.746" name="x" />
    <real value="0.388633" name="y" />
    <real value="0" name="z" />
    </CPoint3d>
     ...
    </vector>
    </CSide>                            // end left side
     ...
     ...
    </CSail>                            // end sail
    </CSailDoc>                         // end file

# Copyright

Copyright (C) Robert Lainé & Jeremy Lainé.

*The authors would appreciate that publications on sails designed with
Sailcut include some acknowledgement of their work.*
