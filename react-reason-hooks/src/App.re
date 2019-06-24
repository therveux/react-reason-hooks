type action =
  | Loaded;

type state = {loading: bool};

let dummyRepo: Repo.githubRepo = {
  name: "Hurobaki/react-native-bridge-module-boilerplate",
  url: "https://api.github.com/orgs/nodejs",
};

[@react.component]
let make = () => {
  let (loading, result) = Hooks.useFetch(~url=dummyRepo.url, ());

  React.useEffect1(() => None, [|result|]);

  <div> <Repository repo=dummyRepo /> </div>;
};