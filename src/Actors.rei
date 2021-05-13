type actor;
// type msg;
type arg =
  | Actor(actor)
  | C(char)
  | S(string)
  | I(int)
  | F(float)
  | L(list(arg))
  | A(array(arg))
  | D(list((string, arg)))
  | LC(list(char))
  | LS(list(string))
  | LI(list(int))
  | LF(list(float))
  | AC(array(char))
  | AS(array(string))
  | AI(array(int))
  | AF(array(float));

type message = (string, list(arg));

let create: (actor => unit) => actor;
let receive: (actor, message => unit) => unit;
let send: (actor, message) => unit;
