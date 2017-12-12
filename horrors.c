// This file is a little story, you read it top to bottom left to right. It is a
// journey of horror and revulsion. Whenever a new Terror is added to our little
// bestiery, I _will_ be using it when convenient later. The point is to
// illustrate the terror that is in the C language available to be misused.


int const array_len = 4;
// this is not allowed:
// char buf[array_len];
enum sizes {ZERO, ONE, TWO, THREE};
// but this is:
char but[TWO];
// and confusingly this also is:
char buu[ZERO];
// or, equivalently (we are conveniently allowed to redeclare it)
char buu[0];
// you can _hold_ buu but never look inside
// TODO



int main() {
  // BLOCKS

  // Blocks are allowed inside functions, like so
  int x = -1;
  {
    x += 1;
    int x = 3;
    int y = x + 1;
  }
  // naturally you can shadow variables, though the fact that you can shadow
  // them and use the outer version both in the same block is a bit surprising

  // STRUCTS
  struct derp {int a, derp;};
  // of course this is fine. Notice that you can reuse the name derp both as the
  // struct tag and as a field in the struct.
  struct derp derp;
  derp.derp = 4;
  // you can reuse the same symbol as the struct tag and the name of a variable
  // with the type of the struct.

  // This is a great time to remember that structs have "tags" not names, always
  // use jargon to punish anyone who tries to understand you.

  // You can hide a struct declaration inside a variable declaration
  struct herp {int a, b;} foo;

  // Structs can't contain their own type, but they can contain a pointer to
  // themselves. This isn't interesting on its own, after all it is how linked
  // lists are commonly implemented. However, combining this with other things,
  // can lead to one very nice kind of statement:
  struct slurp {struct slurp * slurp;} slurp;
  slurp.slurp = &slurp;


  {
    // of course, a struct type can shadow another
    struct herp {char c;};
    struct herp foo;
    foo.c = 'c';
    return 0;
  }

  // this brings us to enums, which look a bit like structs in their declarations

  // a logical extension is allowed for enums, of course:
  enum E {A,B,C,} qux;
  // notice the trailing comma

  // regarding enums, we can say what integer a particular enum value corresponds
  // to
  enum F {D = 1, E, F,} zux;
  // but we can also say it for multiple ones:
  enum G {G = 1, H = 4,} xux;
  // or even something far worse:
  enum H {I = 3, J, K = 3,} uux;
  // Don't get confused, `enum H` and the value `H` don't conflict, the occupy
  // different identifier spaces

  // on the other hand, this is not ok:
  //  typedef enum H H;
  // because value `H` conflicts with the typedef'd type H

}
