```mermaid
flowchart TD
Start([start ]) --> Input[/A and B/]
-->Check{A > B?}
Check --> |Yes| True[/Print = A/]
Check --> |No| False[/Print = B/]
True & False -->Output([output])
```
