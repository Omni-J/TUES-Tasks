-- Basic training for SQl and especially joint
-- Conditions: Table client, club, Visit, service
-- Question for taskt : Koi sa imenata na klientitie i telefonite koito pone vednuj
-- na fitness
--var 4 zad 1
Select  distinct name, tel
From client join visit
  on (uid = id_client)
-- or with select in select
select distinct name, tel
from client, visit
where client.uid = id_client

--var 4 zad 2
-- kolko sa razli4nite clienti koito sa polzvali fitness prez 2016
select count(distinct id_client)
from  visit
where date like "%2016"

-- var 4 zad 3
-- kolko sa clientite koito ne sa polvali fitnesa prez 2016
select distinct uid,  name
from client
where uid not in (
  select distinct id_client
  from visit
  where date line "%2016"
)

-- var 4 zad 4
select distinct client.uid, client.name
from client, visit, club
where client.udi = id_client
and id_club = club.uid
and club.name = "Plovdiv"

-- var 4 zad 5
select distinct client.uid, client.name
from client , visit, club
where client.udi = id_client
nd club.udi = id_club
and client.town = "Sofia"
and club.town = 'Plovdiv'
and client.uid not in (
  select distinct id_client
  from visit, club
  where club.uid = id_club
  and club.town = "Sofia")
)

--var 4 zad 6
select sum(Price)
from service, visit, club
where service_id  = service_id
and club.uid = id_club
and town = "sofia"
and data like "%2016"

--var 4 zad 7
-- na snimka
select distinct client.uid, client.name
from visit, club, client
where club.uid = id_club
and client.udi = id_client
and client.town = club.town
and client.uid not in (
  select distinct client.udi
  from visit, club, client
  where club.udi = id_club
  and client.udi = id_client
  and client.town != club.town
)

--var 4 zad 8 prihoda za vseki fitness prez 2016
select sum(Price), date, club.name
from service, visit, club
where service.uid = service_id
and club.uid = id_club
and date like "%2016"
group by club.name,visit, date;
