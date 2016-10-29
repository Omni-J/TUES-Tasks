?json={
  "a": 1,
  "b": 2,
  "c": 3,
  "x1": 4,
  "x2": 5,
  "url":
  https://raw.githubusercontent.com/thebravoman/software_engineering_2015/master/c37_url_tasks/B_29_Julian_Stoev.txt
}
module['exports'] = function echoHttp (hook) {
  console.log(hook.params);
  console.log(hook.req.path);
  console.log(hook.req.method);
  console.log(hook.env);
  //hook.res.end(JSON.stringify(hook.params, true, 2));

  	var json1 = hook.params.json;
	var args = JSON.parse(json1);

  	var a = args.a;
  	var b = args.b;
  	var c = args.c
	var x1 = args.x1;
  	var x2 = args.x2;
  	var url = args.url;


  	hook.res.write(a.toString());
  	hook.res.write(b.toString());
 	hook.res.write(c.toString());
  	hook.res.write(x1.toString());
  	hook.res.write(x2.toString());
  	hook.res.write(url.toString());

  hook.res.end();
};
