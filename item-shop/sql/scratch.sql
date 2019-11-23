-- Select some stuff

.tables

.schema

.schema eqItems

.mode line

.mode column

.headers on

.width 30

-- (def class-map
--   {:war 1 :clr 2 :pal 4 :rng 8
--    :shd 16 :dru 32 :mnk 64 :brd 128
--    :rog 256 :shm 512 :nec 1024 :wiz 2048
--    :mag 4096 :enc 8192})
-- (def slot-map
--   {:hum 1 :ear 2 :head 4 :face 8 :neck 32 :shoulders 64
--    :arms 128 :back 256 :wrist 512 :range 2048 :hands 4096 :primary 8192
--    :secondary 16384 :fingers 32768 :chest 131072 :legs 262144 :feet 524288
--    :waist 1048576})
select e.name
--, p.name
--, c.name
--, w.name
, e.damage
, e.delay
, e.ac
, e.icon
, e.material, e.color, e.itemtype
from eqItems e
left join eqSpells p on e.proceffect = p.id
left join eqSpells c on e.clickeffect = c.id
left join eqSpells w on e.worneffect = w.id
where 1=1
and slots & 4
and classes & 512
--and icon = 516
and material = 2
order by ac desc
limit 80
;

-- material 3 = plate? 0 = invis cloth
-- material 11 = FBR
-- icon 516 (totemic wrist)
-- icon 622 (large bronze sleeves)
-- select name, icon from eqItems
select name, material from eqItems
where 1=1
--and name like '%flowing black robe%'
and material = 11
limit 10
;

-- material?  color? itemtype?
