type actor = {
  actor_localid: int, /* local number of the actor when it was created */
  actor_host: string /* uniq identifier of the machine on which it was created (20-byte string generated randomly at startup) */
};
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

type local_actor = {
  local_mailbox: Queue.t(message),
  local_handler: message => unit,
};

type remote_actor = {
  remote_ip: string,
  remote_port: int,
};



type local_or_remote =
  | LocalActor(local_actor)
  | RemoteActor(remote_actor);

let actors = Hashtbl.create(1313); /* Should probably be a weak hashtbl */



external create: (actor => unit) => actor = "";
external receive: (actor, message => unit) => unit ="" ;
external send: (actor, message) => unit = "";
