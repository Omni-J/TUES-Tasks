-- Group 1 find it somewhere
-- Task 1
select distinct hotels.name, hotels.town
from visiters, hotels, guests
where guests.name = "Georgi Petrov"
and visiters.Id_guests = Guests.ID_Guests
and visters.ID_hote; = hotels.ID_hotels

--Task 2
select date
from visitors, guests, hotels
where guests.name = "Ivan Petrov"
and visiters.ID_hotel = Hotel.ID_hotel
and hotes.Name = "Sheraton"
and hotels.Town  = "Sofia"
and Guest_uid = vister.Guest_uid


--Task 3
select distinct name
from Hotels
where Town = "Sofia"

--Task 4
select count(ID_visits), Hotel.town
from visiters, hotels, guests
where guests.id_guests = visitors.id_guests
and hotesls.id_hotel = visitors.id_hotel
and hotels.name = "Novotel"
and guest.name = "Ivan Petrov"
group by Hotels.Town

--Task 5
select count(Room.numb)
from visitor
where date like "%2016%"

--Task 5.1 like 5 but for every hotel how many times each of the rooms was used
select hotels.id_hotel, name, count(Rooms.numb)
from visiter, hotel
where date like "%2016%"
and hotels.id_hotel = visiter.id_hotel
group by (id_hotel, room_numb) -- Group by actually joins by the param

--Task 6
select guests.name
from guest, visiter, hotel
where guests.id_guests = visiters.id_guests
and hotels.id_hotels = visiters.id_hotels
and guest.town = hotels.town

--Task 7
select hotel.name
from hotel
where Town = "Sofia"
and id_hotels not in (
  select hotels.name
  from visiter, hotel, guest
  where visiter.id_guest = guest.id_guest
  and visiter.id_hotels = hotel.id_hotels
  and guest.name = "Ideal Petrov"
  and hotel.town = "Sofia"
)

-- Task 8 Had ivan petrov used the same rooms in the the same hotel
select hotel.name, vx.room_numb, date
from visiter vx, visiter xy, guest, hotel
where vx.room_numb = vy.room_numb
and vx.id_hotel = xy.id_hotel
and vx.id_visit != vy.ID_visits
and guest.id_guest = vx.id_guest
and hotel.id_hotel = vx.id_hotel
and guest.name = "Ivan Petrov"
