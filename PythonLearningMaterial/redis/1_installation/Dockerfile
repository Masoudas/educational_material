# docker build . -t redis
# docker run -d -p '6379:6379' -v path_to_data_persistence:/data --name redis-instance redis redis-server

FROM redis
COPY redis.conf /usr/local/etc/redis/redis.conf
CMD [ "redis-server", "/usr/local/etc/redis/redis.conf" ]