type githubRepo = {
  name: string,
  url: string,
};

module Decode = {
  let repo = (repo): githubRepo =>
    Json.Decode.{
      name: repo |> field("name", string),
      url: repo |> field("url", string),
    };
};

let useFetch = (~url: string, ~options=?, ()) => {
  let (loading, setLoading) = React.useState(() => true);
  let (result, setResult) = React.useState(() => []);

  switch (options) {
  | None => Js.log("no options")
  | Some(a) => Js.log(a)
  };

  React.useEffect1(
    () => {
      ignore(
        Js.Promise.(
          Fetch.fetch(url)
          |> then_(Fetch.Response.json)
          |> then_(json =>
               json
               |> Decode.repo
               |> (
                 decodedRepo => {
                   Js.log(decodedRepo);
                   setResult(result => decodedRepo);
                   setLoading(_ => false);
                   Some(decodedRepo);
                 }
               )
               |> resolve
             )
          |> catch(_err => resolve(None))
        ),
      );

      None;
    },
    [||],
  );

  (loading, result);
};