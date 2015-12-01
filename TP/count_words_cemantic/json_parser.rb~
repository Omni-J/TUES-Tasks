require 'json'
require "rubygems"

data = Hash.new

file = open("B_29_Julian_Stoev.json")
json = file.read
data = JSON.parse(json, opts={symbolize_names})

puts data

