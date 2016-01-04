require 'json'

def recursive_search_by_value hash
	hash.each do |key, value|
		if value.is_a?(String) 
			puts value # Draws the node
		else 
			puts "Entering recursion for #{value}"
			recursive_search  
		end
	end
end

def recursive_search_by_key hash

	hash.each do |key, value|
		if key.to_s == "node_name"
			puts value
		else
			recursive_search_by_key value || key #da moje da se pro4ete
		end
	end
	
end

json_file = File.read("test.json") #ARGV[0]
data_hash = JSON.parse(json_file)

recursive_search_by_key data_hash

#data_hash['children'].each do |k, v|
#	puts k
#	puts v
#end
