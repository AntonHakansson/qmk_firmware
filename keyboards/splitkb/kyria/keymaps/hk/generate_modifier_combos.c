#if SHELL_RUNTIME /* $ bash generate_modifier_combos.c
cc generate_modifier_combos.c -o generate_modifier_combos -ggdb -fsanitize=undefined
./generate_modifier_combos > combo_mods.def
exit 0 # */
#endif

// This is free and unencumbered software released into the public domain.
// anton@hakanssn.com

typedef unsigned char    Byte;
typedef __UINT8_TYPE__   U8;
typedef __UINT32_TYPE__  U32;
typedef __INT32_TYPE__   I32;
typedef __INT64_TYPE__   I64;
typedef __UINTPTR_TYPE__ Uptr;
typedef __PTRDIFF_TYPE__ Size;
typedef __SIZE_TYPE__    USize;

#define size_of(s)  (Size)sizeof(s)
#define align_of(s) (Size)_Alignof(s)
#define count_of(s) (size_of((s)) / size_of(*(s)))
#define assert(c)    while((!(c))) __builtin_unreachable()
#define new(a, t, n) (t *) arena_alloc(a, size_of(t), align_of(t), (n))
#define S(s)        (Str){ .buf = (U8 *)(s), .len = count_of((s)) - 1, }
#define S_FMT(s)    (int)(s).len, (s).buf    /* printf("%.*s", S_FMT(str)) */
#define printf      __builtin_printf

typedef struct Arena { Byte *at; Byte *end; } Arena;

__attribute((malloc, alloc_size(2,4), alloc_align(3)))
static Byte *arena_alloc(Arena *a, Size objsize, Size align, Size count)
{
  Size avail = a->end - a->at;
  Size padding = -(USize)(a->at) & (align - 1);
  Size total   = padding + objsize * count;
  assert(total < avail); // TODO: out of memory strategy
  Byte *r = a->at + padding;
  __builtin_memset(r, 0, objsize * count);
  a->at += total;
  return r;
}

typedef struct Str Str;
struct Str {
  U8 *buf;
  Size len;
};

typedef struct Mod Mod;
struct Mod {
  Str name;
  Str key;
};

static void generate(Mod layer, Mod *mods, Size mods_count, Str thumb_key) {
  _Bool in_layer = (layer.name.buf != 0);
  if (in_layer) {
    printf("COMB(%.*s_%.*s, MO(%.*s), %.*s, %.*s)\n", S_FMT(thumb_key), S_FMT(layer.name), S_FMT(layer.name), S_FMT(layer.key), S_FMT(thumb_key));
  }

  U32 mod_bitmask = 1;
  while (mod_bitmask < __builtin_exp2(mods_count)) {
    printf("COMB(");

    //-- Combo name
    printf("%.*s", S_FMT(thumb_key));
    {
      for (Size bit = 0; (1 << bit) <= mod_bitmask; bit++) {
        if (mod_bitmask & (1 << bit)) {
          if (in_layer) { printf("%.*s", S_FMT(layer.name)); }
          printf("_%.*s", S_FMT((mods[bit].name)));
        }
      }
    }
    printf(", ");

    //-- Keycode to send
    {
      Str layer_name = S("0");
      if (in_layer) { layer_name = layer.name; }
      printf("LM(%.*s, ", S_FMT(layer_name));

      _Bool seperator = 0;
      for (Size bit = 0; (1 << bit) <= mod_bitmask; bit++) {
        if (mod_bitmask & (1 << bit)) {
          if (seperator) printf(" | ");
          printf("MOD_%.*s", S_FMT((mods[bit].name)));
          seperator = 1;
        }
      }
      printf("), ");
    }

    //-- Key combination to trigger
    {
      printf("%.*s, ", S_FMT(thumb_key));
      if (in_layer) { printf("%.*s, ", S_FMT(layer.key)); }
      _Bool seperator = 0;
      for (Size bit = 0; (1 << bit) <= mod_bitmask; bit++) {
        if (mod_bitmask & (1 << bit)) {
          if (seperator) printf(", ");
          printf("%.*s", S_FMT((mods[bit].key)));
          seperator = 1;
        }
      }
    }

    printf(")\n");

    mod_bitmask += 1;
  }
}

int main(int argc, char **argv)
{
  printf("/* Program-generated. DO NOT TOUCH. */\n");

  //- left
  {
    Mod layers[] = {
      { },
      { .name = S("_SYM"),  .key = S("KC_A") },
      { .name = S("_SWAP"), .key = S("KC_Z") },
    };
    Mod mods[] = {
      (Mod){ .name = S("LCTL"), .key = S("KC_T") },
      (Mod){ .name = S("LALT"), .key = S("KC_S") },
      (Mod){ .name = S("LGUI"), .key = S("KC_R") },
    };
    for (Size i = 0; i < count_of(layers); i++) {
      generate(layers[i], mods, count_of(mods), S("C_LT"));
    }
  }

  printf("\n");

  //- right
  {
    Mod layers[] = {
      {},
      { .name = S("_NAV"),  .key = S("KC_O")},
      { .name = S("_SWAP"), .key = S("KC_SLSH") },
    };
    Mod mods[] = {
      (Mod){ .name = S("RCTL"), .key = S("KC_N") },
      (Mod){ .name = S("LALT"), .key = S("KC_E") },
      (Mod){ .name = S("LGUI"), .key = S("KC_I") },
    };
    for (Size i = 0; i < count_of(layers); i++) {
      generate(layers[i], mods, count_of(mods), S("C_RT"));
    }
  }

  return 0;
}
