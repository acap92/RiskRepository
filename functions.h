#ifndef FUNCTIONS
#define FUNCTIONS

#include <vector>
#include <list>

bool connected(Territory* start, Territory* end);
bool areNeighbours(Territory* start, Territory* end);
bool contains(Territory* ter, std::list<Territory*> path);
bool contains(Territory* element, std::vector<Territory*> vct);
std::vector<Territory*> bfs2(Territory* start, Territory* end, std::vector<Territory*> discovered, std::vector<Territory*> previous, std::vector<Territory*> visited);
std::vector<Territory*> bfs(Territory* start, Territory* end);
std::list <Territory*> allConected(Territory* start);

#endif // FUNCTIONS
