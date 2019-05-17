-- Select some stuff

.tables

.schema

select e.name
, p.name
, c.name
, w.name
from eqItems e
left join eqSpells p on e.proceffect = p.id
left join eqSpells c on e.clickeffect = c.id
left join eqSpells w on e.worneffect = w.id
limit 3
;
