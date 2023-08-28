# get base image
FROM node:18-alpine

# set (create) & cd to working directory
WORKDIR /app

# copy package.json & yarn.lock to working directory
# this will allow us to install dependencies without copying the entire project
# so that we can take advantage of docker's caching mechanism
COPY package.json yarn.lock ./

# install dependencies
RUN yarn install --production

# copy the rest of the project to working directory
COPY . .

# run node with src/index.js as entrypoint
CMD ["node", "src/index.js"]
