(function (cjs, an) {

var p; // shortcut to reference prototypes
var lib={};var ss={};var img={};
lib.ssMetadata = [
		{name:"Безымянный_3_HTML5 Canvas_atlas_1", frames: [[0,0,179,179],[0,181,162,162]]}
];


(lib.AnMovieClip = function(){
	this.currentSoundStreamInMovieclip;
	this.actionFrames = [];
	this.soundStreamDuration = new Map();
	this.streamSoundSymbolsList = [];

	this.gotoAndPlayForStreamSoundSync = function(positionOrLabel){
		cjs.MovieClip.prototype.gotoAndPlay.call(this,positionOrLabel);
	}
	this.gotoAndPlay = function(positionOrLabel){
		this.clearAllSoundStreams();
		this.startStreamSoundsForTargetedFrame(positionOrLabel);
		cjs.MovieClip.prototype.gotoAndPlay.call(this,positionOrLabel);
	}
	this.play = function(){
		this.clearAllSoundStreams();
		this.startStreamSoundsForTargetedFrame(this.currentFrame);
		cjs.MovieClip.prototype.play.call(this);
	}
	this.gotoAndStop = function(positionOrLabel){
		cjs.MovieClip.prototype.gotoAndStop.call(this,positionOrLabel);
		this.clearAllSoundStreams();
	}
	this.stop = function(){
		cjs.MovieClip.prototype.stop.call(this);
		this.clearAllSoundStreams();
	}
	this.startStreamSoundsForTargetedFrame = function(targetFrame){
		for(var index=0; index<this.streamSoundSymbolsList.length; index++){
			if(index <= targetFrame && this.streamSoundSymbolsList[index] != undefined){
				for(var i=0; i<this.streamSoundSymbolsList[index].length; i++){
					var sound = this.streamSoundSymbolsList[index][i];
					if(sound.endFrame > targetFrame){
						var targetPosition = Math.abs((((targetFrame - sound.startFrame)/lib.properties.fps) * 1000));
						var instance = playSound(sound.id);
						var remainingLoop = 0;
						if(sound.offset){
							targetPosition = targetPosition + sound.offset;
						}
						else if(sound.loop > 1){
							var loop = targetPosition /instance.duration;
							remainingLoop = Math.floor(sound.loop - loop);
							if(targetPosition == 0){ remainingLoop -= 1; }
							targetPosition = targetPosition % instance.duration;
						}
						instance.loop = remainingLoop;
						instance.position = Math.round(targetPosition);
						this.InsertIntoSoundStreamData(instance, sound.startFrame, sound.endFrame, sound.loop , sound.offset);
					}
				}
			}
		}
	}
	this.InsertIntoSoundStreamData = function(soundInstance, startIndex, endIndex, loopValue, offsetValue){ 
 		this.soundStreamDuration.set({instance:soundInstance}, {start: startIndex, end:endIndex, loop:loopValue, offset:offsetValue});
	}
	this.clearAllSoundStreams = function(){
		var keys = this.soundStreamDuration.keys();
		for(var i = 0;i<this.soundStreamDuration.size; i++){
			var key = keys.next().value;
			key.instance.stop();
		}
 		this.soundStreamDuration.clear();
		this.currentSoundStreamInMovieclip = undefined;
	}
	this.stopSoundStreams = function(currentFrame){
		if(this.soundStreamDuration.size > 0){
			var keys = this.soundStreamDuration.keys();
			for(var i = 0; i< this.soundStreamDuration.size ; i++){
				var key = keys.next().value; 
				var value = this.soundStreamDuration.get(key);
				if((value.end) == currentFrame){
					key.instance.stop();
					if(this.currentSoundStreamInMovieclip == key) { this.currentSoundStreamInMovieclip = undefined; }
					this.soundStreamDuration.delete(key);
				}
			}
		}
	}

	this.computeCurrentSoundStreamInstance = function(currentFrame){
		if(this.currentSoundStreamInMovieclip == undefined){
			if(this.soundStreamDuration.size > 0){
				var keys = this.soundStreamDuration.keys();
				var maxDuration = 0;
				for(var i=0;i<this.soundStreamDuration.size;i++){
					var key = keys.next().value;
					var value = this.soundStreamDuration.get(key);
					if(value.end > maxDuration){
						maxDuration = value.end;
						this.currentSoundStreamInMovieclip = key;
					}
				}
			}
		}
	}
	this.getDesiredFrame = function(currentFrame, calculatedDesiredFrame){
		for(var frameIndex in this.actionFrames){
			if((frameIndex > currentFrame) && (frameIndex < calculatedDesiredFrame)){
				return frameIndex;
			}
		}
		return calculatedDesiredFrame;
	}

	this.syncStreamSounds = function(){
		this.stopSoundStreams(this.currentFrame);
		this.computeCurrentSoundStreamInstance(this.currentFrame);
		if(this.currentSoundStreamInMovieclip != undefined){
			var soundInstance = this.currentSoundStreamInMovieclip.instance;
			if(soundInstance.position != 0){
				var soundValue = this.soundStreamDuration.get(this.currentSoundStreamInMovieclip);
				var soundPosition = (soundValue.offset?(soundInstance.position - soundValue.offset): soundInstance.position);
				var calculatedDesiredFrame = (soundValue.start)+((soundPosition/1000) * lib.properties.fps);
				if(soundValue.loop > 1){
					calculatedDesiredFrame +=(((((soundValue.loop - soundInstance.loop -1)*soundInstance.duration)) / 1000) * lib.properties.fps);
				}
				calculatedDesiredFrame = Math.floor(calculatedDesiredFrame);
				var deltaFrame = calculatedDesiredFrame - this.currentFrame;
				if(deltaFrame >= 2){
					this.gotoAndPlayForStreamSoundSync(this.getDesiredFrame(this.currentFrame,calculatedDesiredFrame));
				}
			}
		}
	}
}).prototype = p = new cjs.MovieClip();
// symbols:



(lib.CachedBmp_24 = function() {
	this.initialize(ss["Безымянный_3_HTML5 Canvas_atlas_1"]);
	this.gotoAndStop(0);
}).prototype = p = new cjs.Sprite();



(lib.CachedBmp_25 = function() {
	this.initialize(ss["Безымянный_3_HTML5 Canvas_atlas_1"]);
	this.gotoAndStop(1);
}).prototype = p = new cjs.Sprite();



(lib.Кружки = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Слой_1
	this.instance = new lib.CachedBmp_25();
	this.instance.setTransform(-46.45,-50.4,0.5,0.5);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

	this._renderFirstFrame();

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-46.4,-50.4,81,81);


(lib.Голова = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Слой_1
	this.instance = new lib.CachedBmp_24();
	this.instance.setTransform(-52.45,-50.4,0.5,0.5);

	this.timeline.addTween(cjs.Tween.get(this.instance).wait(1));

	this._renderFirstFrame();

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-52.4,-50.4,89.5,89.5);


(lib.Гусеница = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	// Каркас_21
	this.instance = new lib.Голова("single",0);
	this.instance.setTransform(-23.05,-81.95,1,1,0,0,0,-7.8,-5.7);

	this.instance_1 = new lib.Кружки("single",0);
	this.instance_1.setTransform(-72.5,-52.05,1,1,0,0,0,-6,-10);

	this.instance_2 = new lib.Кружки("single",0);
	this.instance_2.setTransform(-120.5,-38.05,1,1,0,0,0,-6,-10);

	this.instance_3 = new lib.Кружки("single",0);
	this.instance_3.setTransform(-167.5,-16.05,1,1,0,0,0,-6,-10);

	this.instance_4 = new lib.Кружки("single",0);
	this.instance_4.setTransform(-216.5,-34.05,1,1,0,0,0,-6,-10);

	this.instance_5 = new lib.Кружки("single",0);
	this.instance_5.setTransform(-272.5,-22.05,1,1,0,0,0,-6,-10);

	this.instance_6 = new lib.Кружки("single",0);
	this.instance_6.setTransform(-323,-6,1,1,0,0,0,-6,-10);

	this.timeline.addTween(cjs.Tween.get({}).to({state:[{t:this.instance_6,p:{rotation:0,x:-323,y:-6,regY:-10}},{t:this.instance_5,p:{rotation:0,x:-272.5,y:-22.05,regY:-10}},{t:this.instance_4,p:{rotation:0,x:-216.5,y:-34.05,regY:-10}},{t:this.instance_3,p:{rotation:0,x:-167.5,y:-16.05,regY:-10}},{t:this.instance_2,p:{rotation:0,x:-120.5,y:-38.05,regY:-10}},{t:this.instance_1,p:{rotation:0,x:-72.5,y:-52.05,regY:-10}},{t:this.instance,p:{rotation:0,x:-23.05,y:-81.95,regY:-5.7,regX:-7.8}}]}).to({state:[{t:this.instance_6,p:{rotation:0.271,x:-322.95,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:3.4336,x:-272.35,y:-21.8,regY:-10}},{t:this.instance_4,p:{rotation:-2.3419,x:-215.75,y:-30.35,regY:-10}},{t:this.instance_3,p:{rotation:2.433,x:-166.1,y:-14.4,regY:-10}},{t:this.instance_2,p:{rotation:-1.5651,x:-118.15,y:-34.4,regY:-10}},{t:this.instance_1,p:{rotation:4.3055,x:-70.55,y:-49.7,regY:-10}},{t:this.instance,p:{rotation:-6.2186,x:-19,y:-75.8,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:0.5429,x:-322.9,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:6.8681,x:-272.25,y:-21.55,regY:-10}},{t:this.instance_4,p:{rotation:-4.6834,x:-215.3,y:-26.55,regY:-9.9}},{t:this.instance_3,p:{rotation:4.8668,x:-165,y:-12.8,regY:-10}},{t:this.instance_2,p:{rotation:-3.1306,x:-116.3,y:-30.75,regY:-10}},{t:this.instance_1,p:{rotation:8.6116,x:-69.05,y:-47.35,regY:-10}},{t:this.instance,p:{rotation:-12.4379,x:-15.75,y:-69.45,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:0.8148,x:-322.9,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:10.3027,x:-272.15,y:-21.25,regY:-10}},{t:this.instance_4,p:{rotation:-7.0258,x:-214.95,y:-22.95,regY:-10}},{t:this.instance_3,p:{rotation:7.3007,x:-164.1,y:-11.05,regY:-9.9}},{t:this.instance_2,p:{rotation:-4.6966,x:-114.75,y:-27.05,regY:-10}},{t:this.instance_1,p:{rotation:12.9181,x:-67.95,y:-44.95,regY:-10}},{t:this.instance,p:{rotation:-18.6561,x:-13.15,y:-63,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:1.0868,x:-322.9,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:13.7375,x:-272.15,y:-20.9,regY:-9.9}},{t:this.instance_4,p:{rotation:-9.3676,x:-214.85,y:-19.2,regY:-9.9}},{t:this.instance_3,p:{rotation:9.7345,x:-163.55,y:-9.7,regY:-10}},{t:this.instance_2,p:{rotation:-6.2618,x:-113.6,y:-23.35,regY:-10}},{t:this.instance_1,p:{rotation:17.2245,x:-67.35,y:-42.5,regY:-10}},{t:this.instance,p:{rotation:-24.8753,x:-11.3,y:-56.35,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:1.3587,x:-322.9,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:17.1714,x:-272.1,y:-20.65,regY:-9.9}},{t:this.instance_4,p:{rotation:-11.7099,x:-215.15,y:-15.7,regY:-10}},{t:this.instance_3,p:{rotation:12.1676,x:-163.35,y:-8.15,regY:-10}},{t:this.instance_2,p:{rotation:-7.8272,x:-112.8,y:-19.65,regY:-10}},{t:this.instance_1,p:{rotation:21.5304,x:-67.15,y:-40.05,regY:-10}},{t:this.instance,p:{rotation:-31.0947,x:-10.25,y:-49.7,regY:-5.8,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:1.6307,x:-322.9,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:20.6063,x:-271.95,y:-20.5,regY:-10}},{t:this.instance_4,p:{rotation:-14.0519,x:-215.4,y:-12,regY:-10}},{t:this.instance_3,p:{rotation:14.6013,x:-163.4,y:-6.6,regY:-10}},{t:this.instance_2,p:{rotation:-9.3932,x:-112.4,y:-15.8,regY:-9.9}},{t:this.instance_1,p:{rotation:25.837,x:-67.3,y:-37.55,regY:-10}},{t:this.instance,p:{rotation:-37.3137,x:-9.75,y:-42.9,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:1.9028,x:-322.85,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:24.0404,x:-271.9,y:-20.3,regY:-10}},{t:this.instance_4,p:{rotation:-16.3933,x:-215.9,y:-8.35,regY:-10}},{t:this.instance_3,p:{rotation:17.035,x:-163.8,y:-4.95,regY:-9.9}},{t:this.instance_2,p:{rotation:-10.9584,x:-112.45,y:-12.25,regY:-10}},{t:this.instance_1,p:{rotation:30.143,x:-67.9,y:-35.1,regY:-10}},{t:this.instance,p:{rotation:-43.5328,x:-10.15,y:-36.1,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:2.174,x:-322.85,y:-6.15,regY:-10}},{t:this.instance_5,p:{rotation:27.4745,x:-271.8,y:-19.95,regY:-10}},{t:this.instance_4,p:{rotation:-18.7355,x:-216.6,y:-4.8,regY:-9.9}},{t:this.instance_3,p:{rotation:19.4693,x:-164.4,y:-3.65,regY:-10}},{t:this.instance_2,p:{rotation:-12.5238,x:-112.8,y:-8.6,regY:-10}},{t:this.instance_1,p:{rotation:34.4488,x:-68.9,y:-32.7,regY:-10}},{t:this.instance,p:{rotation:-49.752,x:-11.15,y:-29.35,regY:-5.7,regX:-7.7}}]},1).to({state:[{t:this.instance_6,p:{rotation:1.455,x:-322.9,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:26.1569,x:-272,y:-20.7,regY:-10}},{t:this.instance_4,p:{rotation:-17.8184,x:-216.5,y:-6.7,regY:-9.9}},{t:this.instance_3,p:{rotation:16.7682,x:-164.25,y:-4.7,regY:-10}},{t:this.instance_2,p:{rotation:-13.9834,x:-112.95,y:-12.1,regY:-10}},{t:this.instance_1,p:{rotation:34.2061,x:-69.7,y:-37.25,regY:-10}},{t:this.instance,p:{rotation:-48.6542,x:-12.05,y:-34.15,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:0.7353,x:-322.85,y:-6.15,regY:-10}},{t:this.instance_5,p:{rotation:24.8394,x:-272.15,y:-21.25,regY:-10}},{t:this.instance_4,p:{rotation:-16.9015,x:-216.4,y:-8.6,regY:-10}},{t:this.instance_3,p:{rotation:14.068,x:-164.15,y:-5.8,regY:-10}},{t:this.instance_2,p:{rotation:-15.4422,x:-113.35,y:-15.6,regY:-10}},{t:this.instance_1,p:{rotation:33.9624,x:-70.7,y:-41.9,regY:-10}},{t:this.instance,p:{rotation:-47.5565,x:-13.05,y:-39,regY:-5.8,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:0.0157,x:-322.95,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:23.5209,x:-272.35,y:-21.9,regY:-10}},{t:this.instance_4,p:{rotation:-15.9844,x:-216.3,y:-10.5,regY:-10}},{t:this.instance_3,p:{rotation:11.3674,x:-164.2,y:-6.9,regY:-10}},{t:this.instance_2,p:{rotation:-16.9015,x:-113.85,y:-19.05,regY:-10}},{t:this.instance_1,p:{rotation:33.7187,x:-71.85,y:-46.45,regY:-10}},{t:this.instance,p:{rotation:-46.4585,x:-14.2,y:-43.85,regY:-5.8,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-0.7029,x:-322.9,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:22.2037,x:-272.55,y:-22.45,regY:-9.9}},{t:this.instance_4,p:{rotation:-15.0673,x:-216.3,y:-12.45,regY:-10}},{t:this.instance_3,p:{rotation:8.6665,x:-164.25,y:-8,regY:-10}},{t:this.instance_2,p:{rotation:-18.3595,x:-114.5,y:-22.5,regY:-10}},{t:this.instance_1,p:{rotation:33.4752,x:-73.25,y:-50.95,regY:-10}},{t:this.instance,p:{rotation:-45.3604,x:-15.55,y:-48.5,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-1.4226,x:-322.95,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:20.8852,x:-272.75,y:-23.2,regY:-10}},{t:this.instance_4,p:{rotation:-14.1501,x:-216.25,y:-14.4,regY:-10}},{t:this.instance_3,p:{rotation:5.9664,x:-164.3,y:-9.05,regY:-10}},{t:this.instance_2,p:{rotation:-19.8183,x:-115.3,y:-25.8,regY:-9.9}},{t:this.instance_1,p:{rotation:33.2315,x:-74.75,y:-55.4,regY:-10}},{t:this.instance,p:{rotation:-44.2637,x:-17.15,y:-53.3,regY:-5.8,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-2.1425,x:-322.9,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:19.5677,x:-272.95,y:-23.8,regY:-10}},{t:this.instance_4,p:{rotation:-13.2332,x:-216.3,y:-16.35,regY:-10}},{t:this.instance_3,p:{rotation:3.2654,x:-164.5,y:-10.2,regY:-10}},{t:this.instance_2,p:{rotation:-21.2777,x:-116.3,y:-29.2,regY:-9.9}},{t:this.instance_1,p:{rotation:32.9883,x:-76.6,y:-59.75,regY:-9.9}},{t:this.instance,p:{rotation:-43.1655,x:-18.8,y:-57.85,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-2.8618,x:-322.9,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:18.2497,x:-273.2,y:-24.45,regY:-10}},{t:this.instance_4,p:{rotation:-12.3161,x:-216.35,y:-18.1,regY:-9.9}},{t:this.instance_3,p:{rotation:0.5648,x:-164.65,y:-11.2,regY:-10}},{t:this.instance_2,p:{rotation:-22.7364,x:-117.45,y:-32.7,regY:-10}},{t:this.instance_1,p:{rotation:32.7448,x:-78.45,y:-64.2,regY:-10}},{t:this.instance,p:{rotation:-42.0678,x:-20.75,y:-62.5,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-3.5816,x:-322.85,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:16.9316,x:-273.45,y:-25.05,regY:-10}},{t:this.instance_4,p:{rotation:-11.3986,x:-216.5,y:-20.15,regY:-10}},{t:this.instance_3,p:{rotation:-2.1346,x:-164.85,y:-12.25,regY:-10}},{t:this.instance_2,p:{rotation:-24.1958,x:-118.75,y:-36,regY:-10}},{t:this.instance_1,p:{rotation:32.5011,x:-80.55,y:-68.45,regY:-10}},{t:this.instance,p:{rotation:-40.9703,x:-22.85,y:-67.05,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-4.3011,x:-322.9,y:-6.05,regY:-10}},{t:this.instance_5,p:{rotation:15.6138,x:-273.7,y:-25.7,regY:-10}},{t:this.instance_4,p:{rotation:-10.4814,x:-216.6,y:-22.15,regY:-10}},{t:this.instance_3,p:{rotation:-4.8352,x:-165.2,y:-13.35,regY:-10}},{t:this.instance_2,p:{rotation:-25.6544,x:-120.15,y:-39.15,regY:-9.9}},{t:this.instance_1,p:{rotation:32.2578,x:-82.8,y:-72.7,regY:-10}},{t:this.instance,p:{rotation:-39.872,x:-25.15,y:-71.45,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-5.0204,x:-322.85,y:-5.95,regY:-9.9}},{t:this.instance_5,p:{rotation:14.2962,x:-273.95,y:-26.35,regY:-10}},{t:this.instance_4,p:{rotation:-9.5644,x:-216.8,y:-24.05,regY:-10}},{t:this.instance_3,p:{rotation:-7.5361,x:-165.5,y:-14.35,regY:-9.9}},{t:this.instance_2,p:{rotation:-27.1136,x:-121.8,y:-42.45,regY:-10}},{t:this.instance_1,p:{rotation:32.0143,x:-85.3,y:-76.9,regY:-10}},{t:this.instance,p:{rotation:-38.7748,x:-27.6,y:-75.9,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-5.7404,x:-322.85,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:12.9783,x:-274.2,y:-26.95,regY:-10}},{t:this.instance_4,p:{rotation:-8.6471,x:-217.05,y:-26,regY:-10}},{t:this.instance_3,p:{rotation:-10.2362,x:-165.9,y:-15.6,regY:-10}},{t:this.instance_2,p:{rotation:-28.572,x:-123.55,y:-45.65,regY:-10}},{t:this.instance_1,p:{rotation:31.7712,x:-87.95,y:-80.9,regY:-10}},{t:this.instance,p:{rotation:-37.6772,x:-30.2,y:-80.2,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-6.4597,x:-322.85,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:11.6601,x:-274.5,y:-27.5,regY:-10}},{t:this.instance_4,p:{rotation:-7.7301,x:-217.3,y:-27.9,regY:-10}},{t:this.instance_3,p:{rotation:-12.937,x:-166.35,y:-16.65,regY:-10}},{t:this.instance_2,p:{rotation:-30.0317,x:-125.4,y:-48.65,regY:-10}},{t:this.instance_1,p:{rotation:31.5274,x:-90.7,y:-84.8,regY:-10}},{t:this.instance,p:{rotation:-36.5795,x:-32.95,y:-84.45,regY:-5.7,regX:-7.7}}]},1).to({state:[{t:this.instance_6,p:{rotation:-7.179,x:-322.85,y:-6.05,regY:-10}},{t:this.instance_5,p:{rotation:10.3427,x:-274.7,y:-28.15,regY:-10}},{t:this.instance_4,p:{rotation:-6.8126,x:-217.6,y:-29.85,regY:-10}},{t:this.instance_3,p:{rotation:-15.6374,x:-166.8,y:-17.8,regY:-10}},{t:this.instance_2,p:{rotation:-31.4897,x:-127.4,y:-51.65,regY:-10}},{t:this.instance_1,p:{rotation:31.2837,x:-93.8,y:-88.55,regY:-9.9}},{t:this.instance,p:{rotation:-35.4823,x:-36,y:-88.5,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-7.8986,x:-322.85,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:9.0248,x:-275.05,y:-28.75,regY:-10}},{t:this.instance_4,p:{rotation:-5.896,x:-217.95,y:-31.75,regY:-10}},{t:this.instance_3,p:{rotation:-18.3382,x:-167.3,y:-18.9,regY:-10}},{t:this.instance_2,p:{rotation:-32.949,x:-129.65,y:-54.6,regY:-10}},{t:this.instance_1,p:{rotation:31.0405,x:-96.85,y:-92.45,regY:-10}},{t:this.instance,p:{rotation:-34.3841,x:-39.1,y:-92.55,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-8.6187,x:-322.9,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:7.7064,x:-275.25,y:-29.35,regY:-10}},{t:this.instance_4,p:{rotation:-4.9791,x:-218.3,y:-33.65,regY:-10}},{t:this.instance_3,p:{rotation:-21.0385,x:-167.9,y:-20,regY:-10}},{t:this.instance_2,p:{rotation:-34.4081,x:-131.9,y:-57.3,regY:-9.9}},{t:this.instance_1,p:{rotation:30.797,x:-100.15,y:-96.1,regY:-10}},{t:this.instance,p:{rotation:-33.2863,x:-42.4,y:-96.4,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-9.3383,x:-322.8,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:6.3885,x:-275.55,y:-29.95,regY:-10}},{t:this.instance_4,p:{rotation:-4.0618,x:-218.7,y:-35.55,regY:-10}},{t:this.instance_3,p:{rotation:-23.7394,x:-168.55,y:-21.1,regY:-10}},{t:this.instance_2,p:{rotation:-35.8664,x:-134.35,y:-60.2,regY:-10}},{t:this.instance_1,p:{rotation:30.554,x:-103.5,y:-99.65,regY:-10}},{t:this.instance,p:{rotation:-32.1887,x:-45.85,y:-100.2,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-10.0577,x:-322.85,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:5.0713,x:-275.9,y:-30.55,regY:-10}},{t:this.instance_4,p:{rotation:-3.1446,x:-219.15,y:-37.45,regY:-10}},{t:this.instance_3,p:{rotation:-26.4395,x:-169.2,y:-22.2,regY:-10}},{t:this.instance_2,p:{rotation:-37.3256,x:-136.9,y:-62.85,regY:-10}},{t:this.instance_1,p:{rotation:30.3099,x:-107.15,y:-103.15,regY:-10}},{t:this.instance,p:{rotation:-31.0908,x:-49.5,y:-103.95,regY:-5.8,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-10.7777,x:-322.85,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:3.7533,x:-276.2,y:-31.15,regY:-10}},{t:this.instance_4,p:{rotation:-2.2273,x:-219.6,y:-39.35,regY:-10}},{t:this.instance_3,p:{rotation:-29.1398,x:-169.95,y:-23.3,regY:-10}},{t:this.instance_2,p:{rotation:-38.7847,x:-139.65,y:-65.45,regY:-10}},{t:this.instance_1,p:{rotation:30.067,x:-110.85,y:-106.4,regY:-10}},{t:this.instance,p:{rotation:-29.9933,x:-53.1,y:-107.6,regY:-5.8,regX:-7.7}}]},1).to({state:[{t:this.instance_6,p:{rotation:-11.4968,x:-322.9,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:2.4347,x:-276.55,y:-31.7,regY:-10}},{t:this.instance_4,p:{rotation:-1.3107,x:-220.15,y:-41.2,regY:-10}},{t:this.instance_3,p:{rotation:-31.8411,x:-170.75,y:-24.4,regY:-10}},{t:this.instance_2,p:{rotation:-40.2436,x:-142.45,y:-67.9,regY:-10}},{t:this.instance_1,p:{rotation:29.823,x:-114.75,y:-109.65,regY:-10}},{t:this.instance,p:{rotation:-28.896,x:-57.05,y:-110.95,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-12.2168,x:-322.85,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:1.1174,x:-276.8,y:-32.2,regY:-10}},{t:this.instance_4,p:{rotation:-0.3934,x:-220.65,y:-43.1,regY:-10}},{t:this.instance_3,p:{rotation:-34.5414,x:-171.55,y:-25.45,regY:-10}},{t:this.instance_2,p:{rotation:-41.7025,x:-145.35,y:-70.25,regY:-10}},{t:this.instance_1,p:{rotation:29.5802,x:-118.65,y:-112.65,regY:-10}},{t:this.instance,p:{rotation:-27.7983,x:-60.95,y:-114.25,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-12.9361,x:-322.9,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:-0.1993,x:-277.15,y:-32.85,regY:-10}},{t:this.instance_4,p:{rotation:0.5228,x:-221.3,y:-44.95,regY:-10}},{t:this.instance_3,p:{rotation:-37.242,x:-172.45,y:-26.45,regY:-9.9}},{t:this.instance_2,p:{rotation:-43.1618,x:-148.4,y:-72.55,regY:-10}},{t:this.instance_1,p:{rotation:29.3363,x:-122.9,y:-115.55,regY:-9.9}},{t:this.instance,p:{rotation:-26.7007,x:-65,y:-117.5,regY:-5.7,regX:-7.7}}]},1).to({state:[{t:this.instance_6,p:{rotation:-11.3024,x:-322.9,y:-5.95,regY:-9.9}},{t:this.instance_5,p:{rotation:-1.5616,x:-276.4,y:-31.5,regY:-10}},{t:this.instance_4,p:{rotation:-0.5281,x:-220.85,y:-45,regY:-10}},{t:this.instance_3,p:{rotation:-33.8874,x:-171.75,y:-27.45,regY:-10}},{t:this.instance_2,p:{rotation:-36.78,x:-144.9,y:-71.9,regY:-9.9}},{t:this.instance_1,p:{rotation:29.4588,x:-114.75,y:-111.9,regY:-10}},{t:this.instance,p:{rotation:-29.292,x:-57.1,y:-113.6,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-9.668,x:-322.9,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:-2.9231,x:-275.75,y:-30.2,regY:-10}},{t:this.instance_4,p:{rotation:-1.5809,x:-220.5,y:-45,regY:-10}},{t:this.instance_3,p:{rotation:-30.5328,x:-170.95,y:-28.3,regY:-9.9}},{t:this.instance_2,p:{rotation:-30.3988,x:-141.75,y:-71.2,regY:-10}},{t:this.instance_1,p:{rotation:29.5802,x:-107.25,y:-107.55,regY:-10}},{t:this.instance,p:{rotation:-31.8843,x:-49.55,y:-109.15,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-8.0338,x:-322.9,y:-6.05,regY:-10}},{t:this.instance_5,p:{rotation:-4.2844,x:-275.1,y:-28.8,regY:-10}},{t:this.instance_4,p:{rotation:-2.6334,x:-220.2,y:-44.95,regY:-10}},{t:this.instance_3,p:{rotation:-27.1773,x:-170.4,y:-29.25,regY:-10}},{t:this.instance_2,p:{rotation:-24.0177,x:-138.65,y:-70.3,regY:-10}},{t:this.instance_1,p:{rotation:29.7031,x:-100.4,y:-102.6,regY:-10}},{t:this.instance,p:{rotation:-34.476,x:-42.75,y:-104.05,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-6.3999,x:-322.85,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:-5.6465,x:-274.45,y:-27.45,regY:-10}},{t:this.instance_4,p:{rotation:-3.6858,x:-220,y:-44.9,regY:-10}},{t:this.instance_3,p:{rotation:-23.8224,x:-169.95,y:-30.1,regY:-10}},{t:this.instance_2,p:{rotation:-17.6359,x:-135.8,y:-69.25,regY:-10}},{t:this.instance_1,p:{rotation:29.8249,x:-94.25,y:-97.15,regY:-10}},{t:this.instance,p:{rotation:-37.0678,x:-36.55,y:-98.5,regY:-5.8,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-4.7659,x:-322.95,y:-6.05,regY:-10}},{t:this.instance_5,p:{rotation:-7.0081,x:-273.85,y:-26.1,regY:-10}},{t:this.instance_4,p:{rotation:-4.7387,x:-219.85,y:-44.8,regY:-10}},{t:this.instance_3,p:{rotation:-20.4682,x:-169.45,y:-30.9,regY:-10}},{t:this.instance_2,p:{rotation:-11.2551,x:-133.15,y:-68,regY:-10}},{t:this.instance_1,p:{rotation:29.9471,x:-88.7,y:-91.05,regY:-10}},{t:this.instance,p:{rotation:-39.6596,x:-31,y:-92.25,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-3.1314,x:-322.9,y:-6.05,regY:-10}},{t:this.instance_5,p:{rotation:-8.3703,x:-273.35,y:-24.7,regY:-10}},{t:this.instance_4,p:{rotation:-5.7914,x:-219.7,y:-44.7,regY:-10}},{t:this.instance_3,p:{rotation:-17.1128,x:-169.15,y:-31.75,regY:-10}},{t:this.instance_2,p:{rotation:-4.8738,x:-130.7,y:-66.6,regY:-10}},{t:this.instance_1,p:{rotation:30.0685,x:-84,y:-84.6,regY:-10}},{t:this.instance,p:{rotation:-42.2516,x:-26.25,y:-85.65,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:-1.4978,x:-322.95,y:-6.05,regY:-10}},{t:this.instance_5,p:{rotation:-9.732,x:-272.85,y:-23.25,regY:-10}},{t:this.instance_4,p:{rotation:-6.8435,x:-219.7,y:-44.6,regY:-10}},{t:this.instance_3,p:{rotation:-13.7583,x:-168.9,y:-32.4,regY:-9.9}},{t:this.instance_2,p:{rotation:1.5074,x:-128.5,y:-65.05,regY:-10}},{t:this.instance_1,p:{rotation:30.1916,x:-80.05,y:-77.85,regY:-10}},{t:this.instance,p:{rotation:-44.843,x:-22.25,y:-78.8,regY:-5.7,regX:-7.7}}]},1).to({state:[{t:this.instance_6,p:{rotation:0.1355,x:-323,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:-11.0929,x:-272.35,y:-21.85,regY:-10}},{t:this.instance_4,p:{rotation:-7.896,x:-219.75,y:-44.4,regY:-10}},{t:this.instance_3,p:{rotation:-10.4032,x:-168.75,y:-33.3,regY:-10}},{t:this.instance_2,p:{rotation:7.8881,x:-126.5,y:-63.3,regY:-9.9}},{t:this.instance_1,p:{rotation:30.3138,x:-77,y:-70.75,regY:-10}},{t:this.instance,p:{rotation:-47.4346,x:-19.25,y:-71.45,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:1.7698,x:-322.95,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:-12.4548,x:-271.95,y:-20.4,regY:-10}},{t:this.instance_4,p:{rotation:-8.9486,x:-219.9,y:-44.2,regY:-10}},{t:this.instance_3,p:{rotation:-7.0487,x:-168.65,y:-33.9,regY:-9.9}},{t:this.instance_2,p:{rotation:14.2701,x:-124.7,y:-61.7,regY:-10}},{t:this.instance_1,p:{rotation:30.4357,x:-74.7,y:-63.4,regY:-10}},{t:this.instance,p:{rotation:-50.0269,x:-16.95,y:-64,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:3.4038,x:-322.95,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:-13.8168,x:-271.6,y:-18.9,regY:-10}},{t:this.instance_4,p:{rotation:-10.0018,x:-220.05,y:-43.95,regY:-10}},{t:this.instance_3,p:{rotation:-3.6938,x:-168.7,y:-34.75,regY:-10}},{t:this.instance_2,p:{rotation:20.6514,x:-123.15,y:-59.75,regY:-10}},{t:this.instance_1,p:{rotation:30.5583,x:-73.25,y:-55.95,regY:-10}},{t:this.instance,p:{rotation:-52.6183,x:-15.6,y:-56.45,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:4.4317,x:-322.95,y:-5.95,regY:-9.9}},{t:this.instance_5,p:{rotation:-14.5717,x:-271.3,y:-18.05,regY:-10}},{t:this.instance_4,p:{rotation:-12.0513,x:-220.15,y:-43.75,regY:-10}},{t:this.instance_3,p:{rotation:-5.7651,x:-168.45,y:-36.35,regY:-10}},{t:this.instance_2,p:{rotation:18.0877,x:-123.9,y:-63,regY:-10}},{t:this.instance_1,p:{rotation:33.7905,x:-73.95,y:-61.4,regY:-10}},{t:this.instance,p:{rotation:-48.3928,x:-16.25,y:-58.65,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:5.4585,x:-322.9,y:-6.05,regY:-10}},{t:this.instance_5,p:{rotation:-15.3262,x:-271.15,y:-17.05,regY:-10}},{t:this.instance_4,p:{rotation:-14.1013,x:-220.3,y:-43.45,regY:-10}},{t:this.instance_3,p:{rotation:-7.836,x:-168.35,y:-37.95,regY:-10}},{t:this.instance_2,p:{rotation:15.5258,x:-124.8,y:-66.2,regY:-10}},{t:this.instance_1,p:{rotation:37.0229,x:-74.8,y:-66.85,regY:-10}},{t:this.instance,p:{rotation:-44.1672,x:-17.25,y:-60.9,regY:-5.7,regX:-7.7}}]},1).to({state:[{t:this.instance_6,p:{rotation:6.4861,x:-322.85,y:-6.15,regY:-10}},{t:this.instance_5,p:{rotation:-16.081,x:-270.9,y:-16.15,regY:-10}},{t:this.instance_4,p:{rotation:-16.151,x:-220.45,y:-43.2,regY:-10}},{t:this.instance_3,p:{rotation:-9.9067,x:-168.35,y:-39.5,regY:-10}},{t:this.instance_2,p:{rotation:12.9622,x:-125.85,y:-69.3,regY:-10}},{t:this.instance_1,p:{rotation:40.256,x:-75.9,y:-72.25,regY:-10}},{t:this.instance,p:{rotation:-39.9427,x:-18.9,y:-62.95,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:7.514,x:-322.9,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:-16.8348,x:-270.7,y:-15.1,regY:-9.9}},{t:this.instance_4,p:{rotation:-18.2011,x:-220.6,y:-42.9,regY:-10}},{t:this.instance_3,p:{rotation:-11.9779,x:-168.45,y:-41.1,regY:-10}},{t:this.instance_2,p:{rotation:10.3996,x:-127.05,y:-72.45,regY:-10}},{t:this.instance_1,p:{rotation:43.4889,x:-77.25,y:-77.55,regY:-10}},{t:this.instance,p:{rotation:-35.7167,x:-21,y:-65.15,regY:-5.8,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:8.5417,x:-322.9,y:-6.15,regY:-10}},{t:this.instance_5,p:{rotation:-17.59,x:-270.55,y:-14.3,regY:-10}},{t:this.instance_4,p:{rotation:-20.2511,x:-220.85,y:-42.6,regY:-10}},{t:this.instance_3,p:{rotation:-14.0492,x:-168.65,y:-42.7,regY:-10}},{t:this.instance_2,p:{rotation:7.8369,x:-128.4,y:-75.4,regY:-9.9}},{t:this.instance_1,p:{rotation:46.722,x:-78.85,y:-82.8,regY:-10}},{t:this.instance,p:{rotation:-31.4917,x:-23.3,y:-67.2,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:9.5687,x:-322.9,y:-6.1,regY:-10}},{t:this.instance_5,p:{rotation:-18.3445,x:-270.45,y:-13.3,regY:-10}},{t:this.instance_4,p:{rotation:-22.301,x:-221.05,y:-42.3,regY:-10}},{t:this.instance_3,p:{rotation:-16.12,x:-168.9,y:-44.25,regY:-10}},{t:this.instance_2,p:{rotation:5.2741,x:-129.85,y:-78.45,regY:-10}},{t:this.instance_1,p:{rotation:49.9543,x:-80.7,y:-88.05,regY:-10}},{t:this.instance,p:{rotation:-27.2657,x:-26.15,y:-69.3,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:10.5961,x:-322.85,y:-6.15,regY:-10}},{t:this.instance_5,p:{rotation:-19.0996,x:-270.25,y:-12.35,regY:-10}},{t:this.instance_4,p:{rotation:-24.3511,x:-221.3,y:-42,regY:-10}},{t:this.instance_3,p:{rotation:-18.1908,x:-169.25,y:-45.85,regY:-10}},{t:this.instance_2,p:{rotation:2.7113,x:-131.5,y:-81.45,regY:-10}},{t:this.instance_1,p:{rotation:53.1869,x:-82.9,y:-93.1,regY:-9.9}},{t:this.instance,p:{rotation:-23.0404,x:-29.4,y:-71.4,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:11.6244,x:-322.9,y:-6.15,regY:-10}},{t:this.instance_5,p:{rotation:-19.8537,x:-270.2,y:-11.35,regY:-10}},{t:this.instance_4,p:{rotation:-26.4008,x:-221.6,y:-41.7,regY:-10}},{t:this.instance_3,p:{rotation:-20.2622,x:-169.75,y:-47.35,regY:-10}},{t:this.instance_2,p:{rotation:0.1486,x:-133.25,y:-84.3,regY:-10}},{t:this.instance_1,p:{rotation:56.4195,x:-85.1,y:-98.2,regY:-10}},{t:this.instance,p:{rotation:-18.8151,x:-33.05,y:-73.5,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:12.6519,x:-322.85,y:-6.15,regY:-10}},{t:this.instance_5,p:{rotation:-20.6082,x:-270.05,y:-10.45,regY:-10}},{t:this.instance_4,p:{rotation:-28.4503,x:-221.95,y:-41.4,regY:-10}},{t:this.instance_3,p:{rotation:-22.3323,x:-170.3,y:-48.85,regY:-10}},{t:this.instance_2,p:{rotation:-2.4137,x:-135.15,y:-87.15,regY:-10}},{t:this.instance_1,p:{rotation:59.6525,x:-87.75,y:-103.2,regY:-10}},{t:this.instance,p:{rotation:-14.5897,x:-37.1,y:-75.55,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:13.679,x:-322.9,y:-6.05,regY:-9.9}},{t:this.instance_5,p:{rotation:-21.3632,x:-270,y:-9.35,regY:-9.9}},{t:this.instance_4,p:{rotation:-30.5003,x:-222.15,y:-41,regY:-9.9}},{t:this.instance_3,p:{rotation:-24.4039,x:-170.85,y:-50.3,regY:-9.9}},{t:this.instance_2,p:{rotation:-4.9765,x:-137.2,y:-89.9,regY:-10}},{t:this.instance_1,p:{rotation:62.8848,x:-90.55,y:-108.05,regY:-10}},{t:this.instance,p:{rotation:-10.3641,x:-41.5,y:-77.6,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:13.5036,x:-322.9,y:-6.1,regY:-9.9}},{t:this.instance_5,p:{rotation:-20.0174,x:-270,y:-9.65,regY:-10}},{t:this.instance_4,p:{rotation:-25.6728,x:-221.55,y:-40.05,regY:-10}},{t:this.instance_3,p:{rotation:-24.2283,x:-169.55,y:-45.05,regY:-10}},{t:this.instance_2,p:{rotation:-6.5521,x:-135.75,y:-84.45,regY:-10}},{t:this.instance_1,p:{rotation:57.3747,x:-89.65,y:-103.9,regY:-10}},{t:this.instance,p:{rotation:-19.3551,x:-37.9,y:-78.35,regY:-5.8,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:13.3284,x:-322.85,y:-6.2,regY:-10}},{t:this.instance_5,p:{rotation:-18.6711,x:-270.05,y:-9.8,regY:-10}},{t:this.instance_4,p:{rotation:-20.8459,x:-220.8,y:-39.1,regY:-10}},{t:this.instance_3,p:{rotation:-24.0529,x:-168.7,y:-39.7,regY:-10}},{t:this.instance_2,p:{rotation:-8.1282,x:-134.7,y:-79,regY:-10}},{t:this.instance_1,p:{rotation:51.8637,x:-89.1,y:-99.65,regY:-10}},{t:this.instance,p:{rotation:-28.3451,x:-35.2,y:-79.15,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:13.1533,x:-322.8,y:-6.2,regY:-10}},{t:this.instance_5,p:{rotation:-17.3251,x:-270.1,y:-9.95,regY:-10}},{t:this.instance_4,p:{rotation:-16.0182,x:-220.1,y:-38.05,regY:-10}},{t:this.instance_3,p:{rotation:-23.878,x:-168.1,y:-34.3,regY:-10}},{t:this.instance_2,p:{rotation:-9.7044,x:-134.05,y:-73.5,regY:-10}},{t:this.instance_1,p:{rotation:46.3534,x:-89.05,y:-95.4,regY:-10}},{t:this.instance,p:{rotation:-37.3355,x:-33.3,y:-80.25,regY:-5.7,regX:-7.7}}]},1).to({state:[{t:this.instance_6,p:{rotation:12.9783,x:-322.85,y:-6.2,regY:-10}},{t:this.instance_5,p:{rotation:-15.9783,x:-270,y:-10.1,regY:-10}},{t:this.instance_4,p:{rotation:-11.1918,x:-219.5,y:-37.05,regY:-10}},{t:this.instance_3,p:{rotation:-23.7022,x:-167.95,y:-28.9,regY:-10}},{t:this.instance_2,p:{rotation:-11.2801,x:-133.8,y:-68,regY:-10}},{t:this.instance_1,p:{rotation:40.8426,x:-89.4,y:-91.1,regY:-10}},{t:this.instance,p:{rotation:-46.3268,x:-32.45,y:-81.45,regY:-5.7,regX:-7.7}}]},1).to({state:[{t:this.instance_6,p:{rotation:12.8025,x:-322.85,y:-6.25,regY:-10}},{t:this.instance_5,p:{rotation:-14.6321,x:-270.05,y:-10.3,regY:-10}},{t:this.instance_4,p:{rotation:-6.3637,x:-218.9,y:-36.05,regY:-10}},{t:this.instance_3,p:{rotation:-23.5265,x:-168.15,y:-23.5,regY:-9.9}},{t:this.instance_2,p:{rotation:-12.8562,x:-133.9,y:-62.5,regY:-10}},{t:this.instance_1,p:{rotation:35.3319,x:-90.25,y:-86.8,regY:-9.9}},{t:this.instance,p:{rotation:-55.3172,x:-32.7,y:-82.6,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:12.6277,x:-322.8,y:-6.2,regY:-10}},{t:this.instance_5,p:{rotation:-13.2862,x:-270.1,y:-10.4,regY:-10}},{t:this.instance_4,p:{rotation:-1.5371,x:-218.25,y:-35,regY:-10}},{t:this.instance_3,p:{rotation:-23.3514,x:-168.85,y:-18.3,regY:-10}},{t:this.instance_2,p:{rotation:-14.4317,x:-134.45,y:-57.15,regY:-10}},{t:this.instance_1,p:{rotation:29.821,x:-91.4,y:-82.75,regY:-10}},{t:this.instance,p:{rotation:-64.3077,x:-33.75,y:-83.9,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:12.4521,x:-322.8,y:-6.2,regY:-10}},{t:this.instance_5,p:{rotation:-11.9395,x:-270.05,y:-10.55,regY:-10}},{t:this.instance_4,p:{rotation:3.29,x:-217.75,y:-33.95,regY:-10}},{t:this.instance_3,p:{rotation:-23.176,x:-169.85,y:-13.15,regY:-10}},{t:this.instance_2,p:{rotation:-16.0082,x:-135.3,y:-51.85,regY:-10}},{t:this.instance_1,p:{rotation:24.31,x:-93.05,y:-78.5,regY:-9.9}},{t:this.instance,p:{rotation:-73.2985,x:-35.7,y:-85.45,regY:-5.7,regX:-7.7}}]},1).to({state:[{t:this.instance_6,p:{rotation:12.2775,x:-322.75,y:-6.25,regY:-10}},{t:this.instance_5,p:{rotation:-10.5936,x:-270.1,y:-10.75,regY:-10}},{t:this.instance_4,p:{rotation:8.1167,x:-217.2,y:-32.85,regY:-10}},{t:this.instance_3,p:{rotation:-23.0013,x:-171.25,y:-8.05,regY:-10}},{t:this.instance_2,p:{rotation:-17.5837,x:-136.6,y:-46.75,regY:-10}},{t:this.instance_1,p:{rotation:18.7993,x:-95.1,y:-74.65,regY:-10}},{t:this.instance,p:{rotation:-82.2893,x:-38.7,y:-86.85,regY:-5.7,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:12.1023,x:-322.8,y:-6.25,regY:-10}},{t:this.instance_5,p:{rotation:-9.2479,x:-270.1,y:-10.85,regY:-10}},{t:this.instance_4,p:{rotation:12.9442,x:-216.7,y:-31.8,regY:-10}},{t:this.instance_3,p:{rotation:-22.8257,x:-173,y:-3.15,regY:-9.9}},{t:this.instance_2,p:{rotation:-19.1599,x:-138.25,y:-41.75,regY:-10}},{t:this.instance_1,p:{rotation:13.2888,x:-97.5,y:-70.8,regY:-10}},{t:this.instance,p:{rotation:-91.2792,x:-42.65,y:-88.35,regY:-5.8,regX:-7.8}}]},1).to({state:[{t:this.instance_6,p:{rotation:11.927,x:-322.8,y:-6.3,regY:-10}},{t:this.instance_5,p:{rotation:-7.9014,x:-270.1,y:-11.05,regY:-10}},{t:this.instance_4,p:{rotation:17.7717,x:-216.2,y:-30.65,regY:-10}},{t:this.instance_3,p:{rotation:-22.6502,x:-175.1,y:1.35,regY:-10}},{t:this.instance_2,p:{rotation:-20.7355,x:-140.2,y:-36.95,regY:-10}},{t:this.instance_1,p:{rotation:7.7778,x:-100.3,y:-67.1,regY:-10}},{t:this.instance,p:{rotation:-100.2698,x:-47.25,y:-89.95,regY:-5.7,regX:-7.8}}]},1).wait(1));

	this._renderFirstFrame();

}).prototype = p = new cjs.MovieClip();
p.nominalBounds = new cjs.Rectangle(-371.7,-177.5,425,232);


// stage content:
(lib.Безымянный3_HTML5Canvas = function(mode,startPosition,loop) {
	this.initialize(mode,startPosition,loop,{});

	this.actionFrames = [0];
	// timeline functions:
	this.frame_0 = function() {
		this.clearAllSoundStreams();
		 
	}

	// actions tween:
	this.timeline.addTween(cjs.Tween.get(this).call(this.frame_0).wait(60));

	// Слой_1
	this.instance = new lib.Гусеница();
	this.instance.setTransform(165.7,467.45,1,1,0,0,0,-170.9,-46.1);

	this.timeline.addTween(cjs.Tween.get(this.instance).to({guide:{path:[165.8,467.5,336.2,426.8,506.7,386.2,821.6,371.3,1136.6,356.5]}},59).wait(1));

	this._renderFirstFrame();

}).prototype = p = new lib.AnMovieClip();
p.nominalBounds = new cjs.Rectangle(613.2,635.9,716.0999999999999,-87.69999999999993);
// library properties:
lib.properties = {
	id: '1C258FEEDAB34E4080D15594113C195A',
	width: 1280,
	height: 720,
	fps: 30,
	color: "#FFFFFF",
	opacity: 1.00,
	manifest: [
		{src:"images/Безымянный_3_HTML5 Canvas_atlas_1.png?1676995915900", id:"Безымянный_3_HTML5 Canvas_atlas_1"}
	],
	preloads: []
};



// bootstrap callback support:

(lib.Stage = function(canvas) {
	createjs.Stage.call(this, canvas);
}).prototype = p = new createjs.Stage();

p.setAutoPlay = function(autoPlay) {
	this.tickEnabled = autoPlay;
}
p.play = function() { this.tickEnabled = true; this.getChildAt(0).gotoAndPlay(this.getTimelinePosition()) }
p.stop = function(ms) { if(ms) this.seek(ms); this.tickEnabled = false; }
p.seek = function(ms) { this.tickEnabled = true; this.getChildAt(0).gotoAndStop(lib.properties.fps * ms / 1000); }
p.getDuration = function() { return this.getChildAt(0).totalFrames / lib.properties.fps * 1000; }

p.getTimelinePosition = function() { return this.getChildAt(0).currentFrame / lib.properties.fps * 1000; }

an.bootcompsLoaded = an.bootcompsLoaded || [];
if(!an.bootstrapListeners) {
	an.bootstrapListeners=[];
}

an.bootstrapCallback=function(fnCallback) {
	an.bootstrapListeners.push(fnCallback);
	if(an.bootcompsLoaded.length > 0) {
		for(var i=0; i<an.bootcompsLoaded.length; ++i) {
			fnCallback(an.bootcompsLoaded[i]);
		}
	}
};

an.compositions = an.compositions || {};
an.compositions['1C258FEEDAB34E4080D15594113C195A'] = {
	getStage: function() { return exportRoot.stage; },
	getLibrary: function() { return lib; },
	getSpriteSheet: function() { return ss; },
	getImages: function() { return img; }
};

an.compositionLoaded = function(id) {
	an.bootcompsLoaded.push(id);
	for(var j=0; j<an.bootstrapListeners.length; j++) {
		an.bootstrapListeners[j](id);
	}
}

an.getComposition = function(id) {
	return an.compositions[id];
}


an.makeResponsive = function(isResp, respDim, isScale, scaleType, domContainers) {		
	var lastW, lastH, lastS=1;		
	window.addEventListener('resize', resizeCanvas);		
	resizeCanvas();		
	function resizeCanvas() {			
		var w = lib.properties.width, h = lib.properties.height;			
		var iw = window.innerWidth, ih=window.innerHeight;			
		var pRatio = window.devicePixelRatio || 1, xRatio=iw/w, yRatio=ih/h, sRatio=1;			
		if(isResp) {                
			if((respDim=='width'&&lastW==iw) || (respDim=='height'&&lastH==ih)) {                    
				sRatio = lastS;                
			}				
			else if(!isScale) {					
				if(iw<w || ih<h)						
					sRatio = Math.min(xRatio, yRatio);				
			}				
			else if(scaleType==1) {					
				sRatio = Math.min(xRatio, yRatio);				
			}				
			else if(scaleType==2) {					
				sRatio = Math.max(xRatio, yRatio);				
			}			
		}			
		domContainers[0].width = w * pRatio * sRatio;			
		domContainers[0].height = h * pRatio * sRatio;			
		domContainers.forEach(function(container) {				
			container.style.width = w * sRatio + 'px';				
			container.style.height = h * sRatio + 'px';			
		});			
		stage.scaleX = pRatio*sRatio;			
		stage.scaleY = pRatio*sRatio;			
		lastW = iw; lastH = ih; lastS = sRatio;            
		stage.tickOnUpdate = false;            
		stage.update();            
		stage.tickOnUpdate = true;		
	}
}
an.handleSoundStreamOnTick = function(event) {
	if(!event.paused){
		var stageChild = stage.getChildAt(0);
		if(!stageChild.paused){
			stageChild.syncStreamSounds();
		}
	}
}


})(createjs = createjs||{}, AdobeAn = AdobeAn||{});
var createjs, AdobeAn;