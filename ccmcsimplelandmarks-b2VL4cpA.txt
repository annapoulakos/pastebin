--[[
Simple Turtle Landmark Placing Script

Slot Setup:
1: Fuel
2: Landmarks
3-4: Cobble (or other stick block)
]]
local tArgs = {...}
if #tArgs ~= 1 then
	print "Usage:"
	print "Mark <size>"
	return
end

local size = tonumber(tArgs[1])
local fuel = 1
local landmarks = 2
local cobble = 3

function refuel()
	if turtle.getFuelLevel() < 50 then 
		print "Refueling"
		turtle.select(fuel)
		turtle.refuel(1)
	end
end

function dig()
	while turtle.detect() do
		turtle.dig()
		sleep(0.5)
	end
end

function forward()
	refuel()
	turtle.forward()
end

function flr()
	while turtle.getItemCount(cobble) < 1 do
		cobble = cobble + 1
	end
	turtle.select(cobble)
	turtle.placeDown()
end

function landmark()
	turtle.select(landmarks)
	turtle.back()
	turtle.place()
end

function home()
	local y = size - 1
	for n=1,y do
		refuel()
		turtle.back()
	end
end

function line()
	for n=1,size do
		dig()
		forward()
		flr()
	end
end

--[[ Application Start ]]
print "Beginning Landmark Placement Application"
line()
landmark()
home()
turtle.forward()
turtle.turnRight()
line()
landmark()
home()
turtle.turnLeft()
landmark()
print "Finished placing landmarks"