# Haters Gonna Hate
Sample web app written in C using balde, which stores and shows the ip address and the date of each requests made.

## DON'T USE THIS

This was made just for educational purposes, more specifically, for an assignment in which we had to learn how to deploy a web app with docker. Seriously, it has memory leaks. And the "database" is just a plain text file. Who needs SQL when you have fprintf.

Also, this repo contains the whole balde library. I had to modify it in order to expose the ip addresses of all requests.

## Deploying Steps

1. ssh into your server
2. Download and install docker
3. Clone this repo:

    ```sh
    git clone https://github.com/vdrg/hgh.git
    cd hgh
    ```

4. Build the docker image (it will use the [Dockerfile](./Dockerfile) provided in this repo)

    ```sh
    docker build --tag hgh .
    ```

5. Create and run a docker container using the image that was created in the last step

    ```sh
    docker run -p 4000:8080 hgh
    ```

Now the app should be running at port 4000.

## References

https://medium.com/@patriciolpezjuri/empezando-con-docker-86f388316551

https://www.digitalocean.com/community/tutorials/docker-explained-using-dockerfiles-to-automate-building-of-images
