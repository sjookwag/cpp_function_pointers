typedef struct _CHAIR {
  char model[32];
  int price;
  int size;
  void (* Input)(struct _CHAIR*);
  void (* Output)(const struct _CHAIR*);
} CHAIR;

void InitChair(CHAIR* pChair);
