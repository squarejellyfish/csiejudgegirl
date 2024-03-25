typedef struct {
    char name[128];
    int weight;
} Ingredient;

typedef struct {
    Ingredient act[2], inact[5];
    int actn, inactn;
} Medicine;

void init(Medicine *medicine);
int addActive(Medicine *medicine, char *name, int weight);
int addInactive(Medicine *medicine, char *name, int weight);
void print(Medicine *medicine);
int totalWeight(Medicine *medicine);
char *maxIngredient(Medicine *medicine);
