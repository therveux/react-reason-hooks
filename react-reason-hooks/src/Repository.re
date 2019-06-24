[@react.component]
let make = (~repo: Repo.githubRepo) =>
  <div> {ReasonReact.string(repo.name)} </div>;