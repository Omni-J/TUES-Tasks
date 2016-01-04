require "json"

def svg_draw

end

def recursive_search hash 
	hash.each do |key, value|
		if value.is_a?(String) == true
			puts value
			puts "End of printing"		
		else		
			if value.is_a?(Array) == true
				value1 = Hash[value.map {|k, v| [k, v]}]
				puts "Entered recursion for #{value1}"
				recursive_search value1		
			else
			puts "Entered recursion for #{value}"
			recursive_search value
			end
		end
	end
end

json_data = File.read("file.json") #Change to ARGV[0]
data_hash = Hash.new
data_hash = JSON.parse(json_data)

recursive_search data_hash




#puts data_hash
