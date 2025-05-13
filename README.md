# GeoDistance-Calculator

## Goal:
Calculates distances between locations on the surface of the Earth.

### Input:
#### Input Format Description
* Will be read from std::cin
1) Starting Location
    - The first line contains the starting location from which distances will be measured.
2) Number of Target Locations
    - The second line contains a positive integer indicating how many target locations will follow. This number may be very large (e.g., up to one billion).
3) Target Locations
    - Each of the next lines describes one target location, with a total number matching the count given on the second line.

* Each location (starting or target) is formatted as:

```<latitude> <longitude> <location name>```

- Latitude: A non-negative decimal number (0–90) followed by a slash and a direction (N for north or S for south). The values 0/N and 0/S are equivalent.
- Longitude: A non-negative decimal number (0–180) followed by a slash and a direction (E for east or W for west). The values 0/E and 0/W are equivalent, as are 180/E and 180/W.
- Location Name: All text following the longitude, including spaces, represents the location's name.

### Output:
#### Output Format Description
- The words Start Location, followed by a colon and a space, followed by the start location's latitude, followed by a space, followed by the start location's longitude, followed by a space, followed by the name of the start location in parentheses.
- The words Closest Location, followed by a colon and a space, followed by the closest location's latitude, followed by a space, followed by the closest location's longitude, followed by a space, followed by the name of the closest location in parentheses, followed by a space, followed by the distance from the start location to the closest location in miles (surrounded by parentheses).
- The words Farthest Location, followed by a colon and space, followed by a description of the farthest location in the same format as the closest one.

### Example:
```
// Input
> 33.9425/N 118.4081/W Los Angeles International Airport
> 3
> 20.8987/N 156.4305/W Kahului Airport
> 47.4647/N 8.5492/E Zurich Airport
> 23.4356/S 46.4731/W Sao Paolo-Guarulhos International Airport
// Output
> Start Location: 33.9425/N 118.408/W (Los Angeles International Airport)
> Closest Location: 20.8987/N 156.43/W (Kahului Airport) (2483.3 miles)
> Farthest Location: 23.4356/S 46.4731/W (Sao Paolo-Guarulhos International Airport) (6164.9 miles)
```

### How To Run:
1) Clone this repo
2) Run `cmake --preset <macos/linux>` // Unfornately, I do not have support for windows as I do not use that OS :(
3) Run `cmake --build build` inside your project
4) To run the tests, run `./build/GeoLocation-Calculator_gtests`
5) Otherwise, run `./build/GeoLocation-Calculator`
