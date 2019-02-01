        $scope.currently_playing = {
            src: ''
            , audio: angular.element(document.querySelector('myAudio'))
            , cover: ''
            , title: ''
            , width: 0
            , next: function(){
                var len = this.album.tracks.length;
                this.queue++;
                if(this.queue >= len) this.queue = 0;

                this.select_track();
            }
            , prev: function(){
                this.queue--;
                if(this.queue < 0) this.queue = this.album.tracks.length - 1;

                this.select_track();
            }
            , stop: function(){
                this.audio.pause();
            }
            , play: function(){
                if(this.src != ''){
                    this.audio.play();
                }
            }
            , album: {}
            , queue: 0;
            , select_new_album: function(album){
                this.album = album;
                this.queue = 0;
                this.select_track();
            }
            , select_track: function(){
                this.cover = this.album.cover;
                this.src = this.album.tracks[this.queue].src;
                this.title = this.album.tracks[this.queue].name;
            }
            , update: function(){
                // Interval function to update wqidth;
            }
        }