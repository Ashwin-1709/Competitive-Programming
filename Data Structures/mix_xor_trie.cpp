struct node {
  node* ma[2];
  int cnt;
  int best;
  node() {
    cnt = 0;
    best = 0;
    ma[0] = ma[1] = NULL;
  }
};

int merge(node* bit0, node* bit1) {
  bool bit0_end = (bit0 == NULL or !bit0->cnt);
  bool bit1_end = (bit1 == NULL or !bit1->cnt);
  // no elements added till now
  if (bit0_end and bit1_end)
    return 0;
  // only 1 element added in the path
  if (bit0_end)
    return bit1->best;
  if (bit1_end)
    return bit0->best;
  // only 2 elements added
  if (bit0->cnt == 1 and bit1->cnt == 1)
    return bit0->best ^ bit1->best;
  // one of the path has only 1 element
  if (bit0->cnt == 1)
    return bit1->best;
  if (bit1->cnt == 1)
    return bit0->best;
  // multiple paths exist
  return min(bit0->best, bit1->best);
}

void insert(node* cur, int x, int bit) {
  cur->cnt++;

  if (bit < 0) {
    cur->best = 0;
    return;
  }

  int msk = (x >> bit & 1);
  if (cur->ma[msk] == NULL)
    cur->ma[msk] = new node();
  insert(cur->ma[msk], x, bit - 1);
  if (msk and cur->ma[msk]->cnt == 1)
    cur->ma[msk]->best |= (1 << bit);
  cur->best = merge(cur->ma[0], cur->ma[1]);
}

void remove(node* cur, int x, int bit) {
  cur->cnt--;

  if (cur->cnt == 0)
    cur->best = 0;

  if (bit < 0) {
    cur->best = 0;
    return;
  }

  int msk = (x >> bit & 1);
  if (cur->ma[msk] == NULL)
    cur->ma[msk] = new node();
  remove(cur->ma[msk], x, bit - 1);
  if (msk and cur->ma[msk]->cnt == 1)
    cur->ma[msk]->best |= (1 << bit);
  cur->best = merge(cur->ma[0], cur->ma[1]);
}
