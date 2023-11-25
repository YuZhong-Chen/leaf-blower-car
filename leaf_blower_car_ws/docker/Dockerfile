# Base Image : https://hub.docker.com/r/osrf/ros/tags?page=1&name=humble
FROM osrf/ros:humble-desktop-full

LABEL org.opencontainers.image.authors="yuzhong1214@gmail.com"

ARG USERNAME=user
ARG USER_UID=1000
ARG USER_GID=$USER_UID

ENV TERM=xterm-256color
ENV SHELL=/bin/bash
ENV LC_ALL=C.UTF-8

# Create the user
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

# Install common tools
RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    sudo \
    curl \
    git \
    git-extras \
    htop \
    net-tools \
    tmux \
    vim \
    wget \
    python3-pip \
    && rm -rf /var/lib/apt/lists/*

# Install ROS2 RVIZ and Gazebo
RUN apt-get update && apt-get install -y \
    ros-$ROS_DISTRO-gazebo-ros-pkgs \
    ros-$ROS_DISTRO-rviz2 \
    && rm -rf /var/lib/apt/lists/*

# Copy bashrc
COPY .bashrc /home/$USERNAME/.bashrc

# Other settings
USER $USERNAME
CMD ["/bin/bash"]

# Setup environment 
RUN git clone https://github.com/YuZhong-Chen/.setup_env.git ~/.setup_env \
    && cd ~/.setup_env && ./install.sh ros2
