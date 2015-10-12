Dir.glob(ARGV[0] + "*").each do |file|

	result = file.split("/").last.split("_")
#	p result
#	p result[0]
#	p result[1]

 		p "#{result[0]} #{result[1]} #{result[2]} #{result[3].split(".").first}"

	
end


