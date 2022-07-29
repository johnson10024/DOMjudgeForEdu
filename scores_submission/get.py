import requests as req
import base64
import sys

inp = open("file_list", "r")

lines = inp.readlines()

inp.close()

# subid, cid, teamid

for line in lines:
	
	datas = line.split()

	if datas[0] == 'submitid' :
		continue
	
	fname= datas[2] + "_" + datas[0] + ".c"
	outf = open(fname, "w")

	tgt = "http://programming2021.csie.io:7414/api/v4/contests/" + datas[1] + "/submissions/" + datas[0] + "/source-code"
#	print(tgt)

	r = req.get(tgt, auth=('api', 'api'))

	if r.status_code != 200:
		sys.stderr.write("Error on submission " + datas[0] + ", status code =" + str(r.status_code) + "\n")
		outf.close()
		break

	data = r.json()

	enc = data[0]['source']
	dec = base64.b64decode(enc).decode("UTF-8", 'ignore')

	outf.write(dec)
	outf.close()

	sys.stderr.write("submission " + datas[0] + " done\n")
