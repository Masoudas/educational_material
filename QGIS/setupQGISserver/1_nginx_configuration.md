## Configure with fastcgi

After installing nginx, first install apt install spawn-fcgi (which is a better for handling requests, because it creates a new process per request.)

After that, add the following to the /etc/nginx/nginx.conf. For that, we need to add a new server section:

http {

    server{
        location /qgisserver {
            gzip           off;
            include        fastcgi_params;
            fastcgi_pass   unix:/var/run/qgisserver.socket;
        }

    }
}

To check that the syntax of the inserted config is tight, run the following command:

$ nginx -t 

After that, a restart of the service must do the work:
$ sudo systemctl restart nginx

Finally, we can create the following service to run qgis automatically at /etc/systemd/system/qgis-server.service
Enable it by running:
$ sudo systemctl enable --now qgis-server
--------------------
[Unit]
Description=QGIS server
After=network.target

[Service]
;; set env var as needed
;Environment="LANG=en_EN.UTF-8"
;Environment="QGIS_SERVER_PARALLEL_RENDERING=1"
;Environment="QGIS_SERVER_MAX_THREADS=12"
;Environment="QGIS_SERVER_LOG_LEVEL=0"
;Environment="QGIS_SERVER_LOG_STDERR=1"
;; or use a file:
;EnvironmentFile=/etc/qgis-server/env

ExecStart=spawn-fcgi -s /var/run/qgisserver.socket -U www-data -G www-data -n /usr/lib/cgi-bin/qgis_mapserv.fcgi

[Install]
WantedBy=multi-user.target
--------------------



## Running a sample project
Let’s add a sample project. You can use your own, or one from Training demo data:

$ mkdir /home/qgis/projects/
$ cd /home/qgis/projects/
$ wget https://github.com/qgis/QGIS-Training-Data/archive/release_3.16.zip
$ unzip release_3.16.zip
$ mv QGIS-Training-Data-release_3.16/exercise_data/qgis-server-tutorial-data/world.qgs .
$ mv QGIS-Training-Data-release_3.16/exercise_data/qgis-server-tutorial-data/naturalearth.sqlite .

Now that QGIS Server is installed and running, we just have to use it.

Obviously, we need a QGIS project to work on. Of course, you can fully customize your project by defining contact information, precise some restrictions on CRS or even exclude some layers. Everything you need to know about that is described later in Configure your project.

But for now, we are going to use a simple project already configured and previously downloaded in /home/qgis/projects/world.qgs, as described above.

By opening the project and taking a quick look on layers, we know that 4 layers are currently available:

-   airports
-   places
-   countries
-   countries_shapeburst

You don’t have to understand the full request for now but you may retrieve a map with some of the previous layers thanks to QGIS Server by doing something like this in your web browser to retrieve the countries layer:

http://qgis.demo/qgisserver?
  MAP=/home/qgis/projects/world.qgs&
  LAYERS=countries&
  SERVICE=WMS&
  VERSION=1.3.0&
  REQUEST=GetMap&
  CRS=EPSG:4326&
  WIDTH=400&
  HEIGHT=200&
  BBOX=-90,-180,90,180