typedef struct {
    int key;
    char val[128];
} Pair;
typedef struct {
    Pair pairs[1024];
    int n;
} Map;

void init(Map *map);
int map(Map *map, const int key, const char *value);
int numPairs(Map *map);
void print(Map *map);
const char *getValue(Map *map, const int key);
int unmap(Map *map, int key);
int reverseMap(Map *map, const char *value, int keys[]);
